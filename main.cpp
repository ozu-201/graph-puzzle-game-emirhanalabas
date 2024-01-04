//
// Created by ea028490 on 12/14/2023.
//

#include "main.h"
#include "List/Graph/Graph.h"
#include <string>
#include <iostream>
#include <fstream>

int main() {

    int size3 = 0;
    int size4 = 0;
    int size5 = 0;


    std::ifstream file("C:\\Users\\TEMP.OZUN\\CLionProjects\\graph-puzzle-game-emirhanalabas\\dictionary.txt");
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

    list::Graph graph3(size3);
    list::Graph graph4(size4);
    list::Graph graph5(size5);

    std::ifstream file2("C:\\Users\\TEMP.OZUN\\CLionProjects\\graph-puzzle-game-emirhanalabas\\dictionary.txt");
    if (file2.is_open()) {
        std::string line;
        while (std::getline(file2, line)) {
            if (line.length() == 3) {
                graph3.addWords(line);
            } else if (line.length() == 4) {
                graph4.addWords(line);
            } else if (line.length() == 5) {
                graph5.addWords(line);
            }
        }

        file.close();

    } else {
        std::cout << "file not found" << std::endl;
    }

    graph3.connect();
    graph3.dijkstra("can", "cel");





    return 0;
}
