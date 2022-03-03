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

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <algorithm>

struct cat_settings {
    bool number_lines = false;
    bool replace_tabs = false;
};

static std::string replace_tabs(const std::string& string) {
    std::string result;

    int tab_count = std::count(string.begin(), string.end(), '\t');
    result.resize(string.size() + tab_count);
    
    int result_pos = 0;
    for(int i = 0; i < result.size(); i++) {
        if(string[i] == '\t') {
            result[result_pos + 0] = '^';
            result[result_pos + 1] = 'I';
            result_pos += 2;
        } else {
            result[result_pos] = string[i];
            result_pos++;
        }
    }

    return result;
}

int main(int argc, char** argv) {
    // If no file is passed, reading from stdin
    if(argc < 2) {
        std::string line;
        while(true) {
            std::getline(std::cin, line, '\n');
            std::cout << line << std::endl;
        }
    }

    cat_settings settings{};
    int option;
    while((option = getopt(argc, argv, "nT")) != -1) {
        switch(option) {
            case 'n':
                settings.number_lines = true;
                break;
            case 'T':
                settings.replace_tabs = true;
                break;
        }
    }

    for(int i = optind; i < argc; i++) {
        std::ifstream file(argv[i]);
        if(!file.is_open()) {
            std::cerr << "cat: " << argv[i] << ": No such file or directory\n";
            std::exit(1);
        }

        // TODO: extra newline at end of files, check if spec compliant.
        std::string line;
        int line_number = 0;
        while(std::getline(file, line, '\n')) {
            // TODO: left align the numbers?
            if(settings.number_lines) {
                std::cout << " " << line_number << "\t";
            }

            if(settings.replace_tabs) {
                line = replace_tabs(line);
            }
            
            std::cout << line << std::endl;
            line_number++;
        }
    }
}
