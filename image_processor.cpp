#include <iostream>

void Manual() {
    std::cout << "This is the Manual of image_processor programm.\n";
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        Manual();
        return 0;
    }

    std::cout << "Arguments:\n";
    for (int i = 1; i < argc; i++) {
        std::cout << i << " - " << argv[i] << std::endl;
    }

    return 0;
}