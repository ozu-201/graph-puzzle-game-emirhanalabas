//
// Created by ea028490 on 12/14/2023.
//

#include "main.h"
#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("dictionary.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "file not found" << std::endl;
    }

    return 0;
}
