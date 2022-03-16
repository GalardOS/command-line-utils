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

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void redirect_stdout_to_file(const char* file) {
    close(STDOUT_FILENO);
    open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
}

int main(int argc, char** argv) {
    if(argc == 1) {
        fprintf(stderr, "nohup: Missing operand\n");
        fprintf(stderr, "  Try 'man nohup' for more information\n");
        exit(1);
    }

    redirect_stdout_to_file("nohup.out");

    // Arguments passed to the utilities are the same as nohup's but without
    // the first one (which is nohup)
    char** utility_argv = argv + 1;

    // Ignore SIGHUP signal, the whole point of the nohup utility.
    signal(SIGHUP, SIG_IGN);

    // Execute the utility
    execvp(utility_argv[0], utility_argv);

    // Still here? Then something went wrong!
    fprintf(stderr, "nohup: Command %s could not be executed\n", utility_argv[0]);
    return 1;
}
