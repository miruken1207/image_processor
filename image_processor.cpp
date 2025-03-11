#include <iostream>
#include <fstream>

void Manual() {
    std::ifstream manual_file("manual.txt");
    std::cout << manual_file.rdbuf();
    manual_file.close();
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