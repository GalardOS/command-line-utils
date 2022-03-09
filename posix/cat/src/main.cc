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

int main(int argc, char** argv) {
    // If no file is passed, reading from stdin
    if(argc < 2) {
        std::string line;
        while(true) {
            std::getline(std::cin, line, '\n');
            std::cout << line << std::endl;
        }
    }

    for(int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        if(!file.is_open()) {
            std::cerr << "cat: " << argv[i] << ": No such file or directory\n";
            std::exit(1);
        }

        // TODO: extra newline at end of files, check if spec compliant.
        std::string line;
        while(std::getline(file, line, '\n')) {
            std::cout << line << std::endl;
        }
    }
}
