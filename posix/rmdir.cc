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
#include <system_error>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "rmdir: Missing operand\n";
        std::cerr << "  Try 'man rmdir' for more information\n";
        std::exit(1);
    }

    std::filesystem::path dir{argv[1]};

    // If the path does not refer to a directory we can't do anything :(
    if(!std::filesystem::is_directory(dir)) {
        std::cerr << "rmdir: cant remove " << dir.string() << ", not a directory\n";
        std::exit(1);
    }

    std::error_code ec;
    std::filesystem::remove(dir, ec);
    if(ec) {
        std::cerr << "rmdir: " << ec.message() << std::endl;
        std::exit(1);
    }
}
