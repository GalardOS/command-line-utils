#include <iostream>
#include <unistd.h>

struct basename_settings {
    bool multiple = false;
    char newline = '\n';
    std::string suffix{};
};

static std::string remove_string_suffix(const std::string& string, const std::string& suffix) {
    auto found_string = string.find(suffix);
    if(found_string == std::string::npos) {
        return string;
    } else {
        return string.substr(0, string.size() - suffix.size());
    }
} 

static std::string get_basename(const std::string& name, const std::string& suffix) {
    for(int i = name.size() - 1; i > 0; i--) {
        if(name[i] == '/') {
            auto basename = name.substr(i + 1, name.size() - i);
            return remove_string_suffix(basename, suffix);
        }
    }

    return remove_string_suffix(name, suffix);
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
    while((option = getopt(argc, argv, "as:zh")) != -1) {
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
        for(int i = optind; i < argc; i++) {
            std::cout << get_basename(argv[i], settings.suffix) << settings.newline;
        }
    } else {
        std::cout << get_basename(argv[optind], settings.suffix) << settings.newline;
    }
}
