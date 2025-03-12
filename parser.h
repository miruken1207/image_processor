#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

void Manual();

enum class Filter;

Filter string_to_filter(std::string str);

bool check_input_file(std::string file_name);

void Parser(int argc, char *argv[]);