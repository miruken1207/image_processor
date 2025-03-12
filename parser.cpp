#include "parser.h"

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

bool check_input_file(std::string file_name) {
    std::ifstream file(file_name, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    char header[2];
    file.read(header, 2);
    if (file.gcount() != 2 || header[0] != 'B' || header[1] != 'M') {
        file.close();
        return false;
    }

    file.close();
    return true;
}

bool check_output_directory(std::string path) {
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        return true;
    }
    return false;
}

std::vector<std::string> char_arr_to_vector(int argc, char *argv[]) {
    std::vector<std::string> result_vector;
    for (int i = 0; i < argc; i++) {
        result_vector.emplace_back(argv[i]);
    }
    return result_vector;
}

void Parser(int argc, char *argv[]) {
    if (argc == 1) {
        Manual();
        return;
    }

    std::vector<std::string> arg_vector = char_arr_to_vector(argc, argv);
    if (arg_vector.size() < 4) {
        std::cerr << "Ошибка: недостаточно аргументов!" << std::endl;
        return;
    }

    if (!check_input_file(arg_vector[1])) {
        std::cerr << "Ошибка: Неправильный входной файл " << arg_vector[1] << " !" << std::endl;
        return;
    } else {
        std::cout << "Входной файл: " << arg_vector[1] << std::endl;
    }

    if (!check_output_directory(arg_vector[2])) {
        std::cerr << "Ошибка: Неправильно указан выходной путь " << arg_vector[2] << " !" << std::endl;
        return;
    } else {
        std::cout << "Выходной файл: " << arg_vector[2] << std::endl;
    }

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