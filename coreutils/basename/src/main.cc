#include <iostream>

std::string get_basename(const std::string& name) {
    for(int i = name.size() - 1; i > 0; i--) {
        if(name[i] == '/') {
            return name.substr(i + 1, name.size() - i);
        }
    }

    return name;
}

int main(int argc, char** argv) {
    // If no arguments are passed, program exits with error message.
    if(argc < 2) {
        std::cerr << "basename: Missing operand\n";
        std::cerr << "  Try 'basename -h' for more information\n";
    }

    for(int i = 1; i < argc; i++) {
        std::cout << get_basename(argv[i]) << std::endl;
    }

}
