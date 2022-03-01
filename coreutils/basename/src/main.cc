#include <iostream>
#include <unistd.h>

struct basename_settings {
    bool multiple = false;
    char newline = '\n';
    std::string suffix{};
};

std::string get_basename(const std::string& name) {
    for(int i = name.size() - 1; i > 0; i--) {
        if(name[i] == '/') {
            return name.substr(i + 1, name.size() - i);
        }
    }

    return name;
}

void print_help_message() {
    std::cout << "Available options:\n";
    std::cout << "\t-a,        support multiple arguments and treat each as a NAME\n";
    std::cout << "\t-s SUFFIX, remove a trailing SUFFIX\n";
    std::cout << "\t-z,        end each output line with NUL, not newline\n";
    std::cout << "\t-h,        display this help and exit\n";
}

int main(int argc, char** argv) {
    // If no arguments are passed, program exits with error message.
    if(argc < 2) {
        std::cerr << "basename: Missing operand\n";
        std::cerr << "  Try 'basename -h' for more information\n";
        std::exit(1);
    }

    int option;
    basename_settings settings{};
    while((option = getopt(argc, argv, "a:szh")) != -1) {
        switch(option) {
            case 'a':
                settings.multiple = true;
                break;

            case 's':
                settings.suffix = std::string(optarg);
                break;

            case 'z':
                settings.newline = '\0';
                break;

            case 'h':
                print_help_message();
                std::exit(0);
        }
    }

    if(settings.multiple) {
        for(int i = optind - 1; i < argc; i++) {
            std::cout << get_basename(argv[i]) << settings.newline;
        }
    } else {
        std::cout << get_basename(argv[optind]) << settings.newline;
    }
}
