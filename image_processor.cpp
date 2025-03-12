#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void Manual() {
    std::ifstream manual_file("manual.txt");
    std::cout << manual_file.rdbuf();
    manual_file.close();
}

enum class Filter { CROP, GRAYSCALE, NEGATIVE, SHARPENING, EDGE_DETECTION, GAUSSIAN_BLUR, NOFILTER };

Filter string_to_filter(std::string str) {
    if (str == "-crop") {
        return Filter::CROP;
    }
    if (str == "-gs") {
        return Filter::GRAYSCALE;
    }
    if (str == "-neg") {
        return Filter::NEGATIVE;
    }
    if (str == "-sharp") {
        return Filter::SHARPENING;
    }
    if (str == "-edge") {
        return Filter::EDGE_DETECTION;
    }
    if (str == "-blur") {
        return Filter::GAUSSIAN_BLUR;
    } else {
        return Filter::NOFILTER;
    }
}

void Parser(int argc, char *argv[]) {

    if (argc == 1) {
        Manual();
        return;
    }

    std::vector<std::string> arg_vector;
    for (int i = 0; i < argc; i++) {
        arg_vector.emplace_back(argv[i]);
    }

    std::cout << "Входной файл: " << arg_vector[1] << std::endl;
    std::cout << "Выходной файл: " << arg_vector[2] << std::endl;

    for (int i = 3; i < arg_vector.size(); i++) {
        Filter filter = string_to_filter(arg_vector[i]);
        switch (filter) {
            case Filter::CROP:
                std::cout << "применяем " << arg_vector[i] << " с аргументами " << arg_vector[++i] << " "
                          << arg_vector[++i] << std::endl;
                break;
            case Filter::GRAYSCALE:
                std::cout << "применяем " << arg_vector[i] << std::endl;
                break;
            case Filter::NEGATIVE:
                std::cout << "применяем " << arg_vector[i] << std::endl;
                break;
            case Filter::SHARPENING:
                std::cout << "применяем " << arg_vector[i] << std::endl;
                break;
            case Filter::EDGE_DETECTION:
                std::cout << "применяем " << arg_vector[i] << " с аргументом " << arg_vector[++i] << std::endl;
                break;
            case Filter::GAUSSIAN_BLUR:
                std::cout << "применяем " << arg_vector[i] << " с аргументом " << arg_vector[++i] << std::endl;
                break;
            case Filter::NOFILTER:
                std::cout << arg_vector[i] << " - это не фильтр" << std::endl;
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    Parser(argc, argv);

    return 0;
}