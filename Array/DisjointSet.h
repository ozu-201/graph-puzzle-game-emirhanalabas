//
// Created by ea028490 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_EMIRHANALABAS_DISJOINTSET_H
#define GRAPH_PUZZLE_GAME_EMIRHANALABAS_DISJOINTSET_H

#include "Set.h"

class DisjointSet {
private:
    Set* sets;
    int count;
public:
    DisjointSet(int* elements, int count);
    DisjointSet(int count);
    ~DisjointSet();
    int findSetRecursive(int index);
    int findSetIterative(int index);
    void unionOfSets(int index1, int index2);
};

#endif //GRAPH_PUZZLE_GAME_EMIRHANALABAS_DISJOINTSET_H
