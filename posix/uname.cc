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

#include <iostream>
#include <string>

std::string hardware_type() {
    return std::string{"unknown"};
}

std::string hostname() {
    char hostname[255];
    gethostname(hostname, 255);
    
    return std::string{hostname};
}

std::string os_release() {
    return std::string{"DEVELOPMENT"};
}

std::string os_name() {
    return std::string{"GalardOS"};
}



struct uname_flags {
    bool hardware_type = false;
    bool hostname = false;
    bool os_release = false;
    bool os_name = false;
};

static uname_flags get_flags(int argc, char** argv) {
    uname_flags flags{};

    int option_count = 0;
    int option;
    while((option = getopt(argc, argv, "mnrsv")) != -1) {
        switch(option) {
            case 'm':
                flags.hardware_type = true;
                break;
            case 'n':
                flags.hostname = true;
                break;
            case 'r':
                flags.os_release = true;
                break;
            case 's':
                flags.os_name = true;
                break;
            case 'v':
                flags.os_release = true;
                break;
        }

        option_count++;
    }

    // If no options have been selected, add the -s flag automatically.
    if(option_count == 0) {
        flags.os_name = true;
    }

    return flags;
} 

int main(int argc, char** argv) {
    auto flags = get_flags(argc, argv);

    if(flags.hardware_type) {
        std::cout << hardware_type() << ' ';
    }

    if(flags.hostname) {
        std::cout << hostname() << ' ';
    }

    if(flags.os_release) {
        std::cout << os_release() << ' ';
    }

    if(flags.os_name) {
        std::cout << os_name() << ' ';
    }

    std::cout << std::endl;
}
