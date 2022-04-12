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

#include <sys/mman.h>
#include <getopt.h>
#include <fcntl.h>

#include <iostream>
#include <filesystem>

struct cmp_flags {
    bool silent = false;
};

cmp_flags get_flags(int argc, char** argv) {
    cmp_flags flags{};

    int option;
    while((option = getopt(argc, argv, "s")) != -1) {
        switch(option) {
            case 's':
                flags.silent = true;
        }
    }

    return flags;
}

int main(int argc, char** argv) {
    auto flags = get_flags(argc, argv);

    if(argc - optind != 2) {
        std::cerr << "cmp: Missing operand\n";
        std::cerr << "  Try 'man cmp' for more information\n";
        std::exit(1);
    }

    std::filesystem::path file0_path{argv[optind + 0]};
    std::filesystem::path file1_path{argv[optind + 1]};

    // If files are of different sizes, we already know that they are different, so we don't need
    // to traverse the whole file.
    auto file0_size = std::filesystem::file_size(file0_path);
    auto file1_size = std::filesystem::file_size(file1_path);
    if(file0_size != file1_size) {
        int difference_point = std::min(file0_size, file1_size);
        std::cout << file0_path.string() << " and " << file1_path.string() << " differ: byte " << difference_point << std::endl;
        std::exit(1);
    }

    int file0 = open(argv[optind + 0], 0);
    int file1 = open(argv[optind + 1], 0);

    char* file0_content = static_cast<char*>(mmap(nullptr, std::filesystem::file_size(file0_path), PROT_READ, MAP_PRIVATE, file0, 0));
    char* file1_content = static_cast<char*>(mmap(nullptr, std::filesystem::file_size(file1_path), PROT_READ, MAP_PRIVATE, file1, 0));

    for(size_t i = 0; i < file0_size; i++) {
        if(file0_content[i] != file1_content[i]) {
            std::cout << file0_path.string() << " and " << file1_path.string() << " differ: byte " << i << std::endl;
            std::exit(1);
        }
    }

    // If code arrives here, the buffers are equal, and thus we notify that they are equal by exit code 0.
    std::exit(0);
}
