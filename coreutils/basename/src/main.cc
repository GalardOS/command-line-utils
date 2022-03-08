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
#include <unistd.h>

static std::string calculate_basename(const std::string& string) {
    for(int i = string.size() - 1; i > 0; i--) {
        if(string[i] == '/') {
            return string.substr(i + 1, string.size() - i);
        }
    }

    return std::string{};
}

static std::string remove_suffix(const std::string& string, const std::string& suffix) {
    auto found_string = string.find(suffix);
    if(found_string == std::string::npos) {
        return string;
    } else {
        return string.substr(0, string.size() - suffix.size());
    }
}

int main(int argc, char** argv) {
    // If no arguments are passed, program exits with error message.
    if(argc < 2) {
        std::cerr << "basename: Missing operand\n";
        std::cerr << "  Try 'basename -h' for more information\n";
        std::exit(1);
    }
    
    const std::string string{argv[1]};
    std::string to_print = calculate_basename(string);

    if(argc == 3) {
        const std::string suffix{argv[2]};
        to_print = remove_suffix(to_print, suffix);
    }

    std::cout << to_print << std::endl;
}
