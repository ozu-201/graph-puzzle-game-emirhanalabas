//
// Created by ea028490 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_EMIRHANALABAS_GRAPH_H
#define GRAPH_PUZZLE_GAME_EMIRHANALABAS_GRAPH_H

#include <string>
#include "EdgeList.h"
#include "../../General/AbstractGraph.h"

namespace list {

    class Graph : public AbstractGraph{
    private:
        EdgeList *edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void connectedComponentsDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source);
        void prim();
        std::string *words;
        int wordNumber;

        void addWords(std::string word);

        void connect();

        void dijkstra(std::string start, std::string end);

        int findIndex(std::string s);

    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
        Edge* edgeList(int& edgeCount) override;

        void addEdge(std::string from, std::string to);

        void BFS(std::string from, std::string to);
    };

}

#endif //GRAPH_PUZZLE_GAME_EMIRHANALABAS_GRAPH_H
