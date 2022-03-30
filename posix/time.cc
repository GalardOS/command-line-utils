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

struct time_flags {
    bool print_to_stderr = false;
};

static time_flags get_flags(int argc, char** argv) {
    time_flags flags{};

    int option = 0;
    while((option = getopt(argc, argv, "p")) != -1) {
        switch(option) {
            case 'p':
                flags.print_to_stderr = true;
                break;
        }
    }

    return flags;
}

int main(int argc, char** argv) {
    auto flags = get_flags(argc, argv);

    auto pid = fork();
    if(pid == 0) {
        char** child_argv = argv + 1;
        execvp(child_argv[0], child_argv);

        std::cerr << "time: could not execute command " << child_argv[0] << std::endl; 
        std::exit(1);
    }

    
}