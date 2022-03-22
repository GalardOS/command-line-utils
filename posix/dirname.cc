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
#include <filesystem>

std::string calculate_dirname(const std::string& string) {
    for(int i = string.size() - 1; i > 0; i--) {
        if(string[i] == '/') {
            return string.substr(0, i + 1);
        }
    }

    return std::string{"./"};
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "dirname: Missing operand\n";
        std::cerr << "  Try 'man dirname' for more information\n";
        std::exit(1);
    }

    std::cout << calculate_dirname(argv[1]) << std::endl;
}
