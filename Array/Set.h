//
// Created by ea028490 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_EMIRHANALABAS_SET_H
#define GRAPH_PUZZLE_GAME_EMIRHANALABAS_SET_H

#ifndef DATASTRUCTURES_CPP_SET_H
#define DATASTRUCTURES_CPP_SET_H


class Set {
private:
    int data;
    int parent;
    int depth;
public:
    Set(int data, int index);
    Set();
    int getParent() const;
    int getDepth() const;
    void setParent(int parent);
    void incrementDepth();
};


#endif //DATASTRUCTURES_CPP_SET_H

#endif //GRAPH_PUZZLE_GAME_EMIRHANALABAS_SET_H
