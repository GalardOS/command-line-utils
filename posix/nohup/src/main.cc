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

#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include <string>
#include <iostream>

static void redirect_stdout_to_file(const std::string& file) {
    close(STDOUT_FILENO);
    open(file.c_str(), O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
}

int main(int argc, char** argv) {
    int utility_argc = argc - 1;
    char** utility_argv = argv + 1;

    redirect_stdout_to_file("./nohup.out");

    signal(SIGHUP, SIG_IGN);
    execvp(utility_argv[0], utility_argv);
    std::cerr << "nohup: command " << utility_argv[0] << " can't be executed\n";
    std::exit(1);
}
