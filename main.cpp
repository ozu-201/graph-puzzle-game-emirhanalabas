//
// Created by ea028490 on 12/14/2023.
//

#include "main.h"
#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>

int main() {

    int size3 = 0;
    int size4 = 0;
    int size5 = 0;


    std::ifstream file("C:\\Users\\TEMP\\Documents\\GitHub\\graph-puzzle-game-emirhanalabas\\dictionary.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.length() == 3) {
                size3++;
            } else if (line.length() == 4) {
                size4++;
            } else if (line.length() == 5) {
                size5++;
            }
        }

        std::cout << "Number of words with 3 letter:" << std::endl;
        std::cout << size3 << std::endl;
        std::cout << "Number of words with 4 letter:" << std::endl;
        std::cout << size4 << std::endl;
        std::cout << "Number of words with 5 letter:" << std::endl;
        std::cout << size5 << std::endl;
        file.close();

    } else {
        std::cout << "file not found" << std::endl;
    }

    array::Graph graph3(size3);
    array::Graph graph4(size4);
    array::Graph graph5(size5);

    int index3 = 0;
    int index4 = 0;
    int index5 = 0;

    std::ifstream file2("C:\\Users\\TEMP\\Documents\\GitHub\\graph-puzzle-game-emirhanalabas\\dictionary.txt");
    if (file2.is_open()) {
        std::string line;
        while (std::getline(file2, line)) {
            if (line.length() == 3) {
                graph3.addWords(index3, line);
                index3++;
            } else if (line.length() == 4) {
                graph4.addWords(index4, line);
                index4++;
            } else if (line.length() == 5) {
                graph5.addWords(index5, line);
                index5++;
            }
        }

        file.close();

    } else {
        std::cout << "file not found" << std::endl;
    }



    std::cout << "Edges for words with 3 letters:" << std::endl;

    graph3.connect();
    graph3.printEdges();

    std::cout << "Edges for words with 4 letters:" << std::endl;

    graph4.connect();
    graph4.printEdges();



    return 0;
}
