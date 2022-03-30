/*
 * This project is provided under the GNU GPL v2 license, more information can 
 * found on https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    - Iker Galardi
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <filesystem>
#include <iostream>

struct touch_flags {
    bool change_access_time = false;
    bool change_modify_time = false;
};

static touch_flags get_flags(int argc, char** argv) {
    touch_flags flags{};

    int option;
    while((option = getopt(argc, argv, "am")) != -1) {
        switch(option) {
            case 'a':
                flags.change_access_time = true;
                break;
            case 'm':
                flags.change_modify_time = true;
                break;
        }
    }

    // SPEC: If neither the -a nor -m options were specified, touch shall behave as if both
    //       the -a and -m options were specified.
    if(!flags.change_access_time && !flags.change_modify_time) {
        flags.change_access_time = true;
        flags.change_modify_time = true;
    }

    return flags;
}

int main(int argc, char** argv) {
    auto flags = get_flags(argc, argv);

    if(optind - argc <= 0) {
        std::cerr << "touch: Missing operand\n";
        std::cerr << "  Try 'man touch' for more information\n";
    }

    for(int i = optind; i < argc; i++) {
        std::filesystem::path file{argv[i]};

        // SPEC: If the file does not exist, then the file should be created.
        if(!std::filesystem::exists(file)) {
            int fd = creat(file.string().c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        } else {
            timespec times_to_set[2] {
                {0, UTIME_OMIT},
                {0, UTIME_OMIT}
            };

            if(flags.change_access_time) {
                times_to_set[0].tv_nsec = UTIME_NOW;
            }

            if(flags.change_modify_time) {
                times_to_set[1].tv_nsec = UTIME_NOW;
            }
            utimensat(AT_FDCWD, file.string().c_str(), times_to_set, 0);
        }
    }
}
