//
// Created by ea028490 on 12/14/2023.
//


#include "Graph.h"
#include "../../Array/DisjointSet.h"
#include "../Queue.h"
#include "../../Array/Heap/MinHeap.h"
#include <string>
#include <iostream>

namespace list {

    Graph::Graph(int _vertexCount) : AbstractGraph(_vertexCount){
        edges = new EdgeList[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = EdgeList();
        }
        words = new std::string[vertexCount];
        wordNumber = 0;
    }

    void Graph::addEdge(int from, int to) {
        Edge* edge = new Edge(from, to, 1);
        edges[from].insert(edge);
    }

    void Graph::addEdge(int from, int to, int weight) {
        Edge* edge = new Edge(from, to, weight);
        edges[from].insert(edge);
    }

    Graph::~Graph() {
        delete[] edges;
    }

    void Graph::connectedComponentsDisjointSet() {
        Edge* edge;
        int toNode;
        DisjointSet sets = DisjointSet(vertexCount);
        for (int fromNode = 0; fromNode < vertexCount; fromNode++){
            edge = edges[fromNode].getHead();
            while (edge != nullptr){
                toNode = edge->getTo();
                if (sets.findSetRecursive(fromNode) != sets.findSetRecursive(toNode)){
                    sets.unionOfSets(fromNode, toNode);
                }
                edge = edge->getNext();
            }
        }
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        Edge* edge;
        int toNode;
        edge = edges[fromNode].getHead();
        while (edge != nullptr){
            toNode = edge->getTo();
            if (!visited[toNode]){
                visited[toNode] = true;
                depthFirstSearch(visited, toNode);
            }
            edge = edge->getNext();
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        Edge* edge;
        int fromNode, toNode;
        Queue queue = Queue();
        queue.enqueue(new Node(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue()->getData();
            edge = edges[fromNode].getHead();
            while (edge != nullptr) {
                toNode = edge->getTo();
                if (!visited[toNode]){
                    visited[toNode] = true;
                    queue.enqueue(new Node(toNode));
                }
                edge = edge->getNext();
            }
        }
    }

    void Graph::BFS(std::string from, std::string to) {
        Edge* edge;
        int fromIndex = findIndex(from), toIndex = findIndex(to);
        bool* visited[1000];
        Queue queue = Queue();
        queue.enqueue(new Node(fromIndex));
        while (!queue.isEmpty()){
            fromIndex = queue.dequeue()->getData();
            edge = edges[fromIndex].getHead();
            while (edge != nullptr) {
                toIndex = edge->getTo();
                if (!visited[toIndex]){
                    visited[toIndex] = reinterpret_cast<bool *>(true);
                    queue.enqueue(new Node(toIndex));
                }
                edge = edge->getNext();
            }
        }
    }

    Path *Graph::bellmanFord(int source) {
        Edge* edge;
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                edge = edges[fromNode].getHead();
                while (edge != nullptr){
                    int toNode = edge->getTo();
                    int newDistance = shortestPaths[fromNode].getDistance() + edge->getWeight();
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                    edge = edge->getNext();
                }
            }
        }
        return shortestPaths;
    }

    Path *Graph::dijkstra(int source) {
        Edge* edge;
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            edge = edges[fromNode].getHead();
            while (edge != nullptr){
                int toNode = edge->getTo();
                int newDistance = shortestPaths[fromNode].getDistance() + edge->getWeight();
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
                edge = edge->getNext();
            }
        }
        return shortestPaths;
    }

    Edge *Graph::edgeList(int& edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                edgeCount++;
                edge = edge->getNext();
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                list[index] = Edge(edge->getFrom(), edge->getTo(), edge->getWeight());
                index++;
                edge = edge->getNext();
            }
        }
        return list;
    }

    void Graph::prim() {
        Path* paths = initializePaths(0);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(paths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            Edge* edge = edges[fromNode].getHead();
            while (edge != nullptr){
                int toNode = edge->getTo();
                if (paths[toNode].getDistance() > edge->getWeight()){
                    int position = heap.search(toNode);
                    heap.update(position, edge->getWeight());
                    paths[toNode].setDistance(edge->getWeight());
                    paths[toNode].setPrevious(fromNode);
                }
                edge = edge->getNext();
            }
        }
    }

    void Graph::addWords(std::string word) {
        words[wordNumber] = std::move(word);
        wordNumber++;
    }

    void Graph::addEdge(std::string from, std::string to) {
        int l = from.length();
        int indexFrom = findIndex(from);
        int indexTo = findIndex(to);
        int diffCount = 0;

        for (int j = 0; j < l; j++) {
            if (from[j] != to[j]) {
                diffCount++;
            }
        }

        if (diffCount == 1) {
            Edge* edge = new Edge(indexFrom, indexTo, 1);
            edges[indexFrom].insert(edge);
            Edge* edge2 = new Edge(indexTo, indexFrom, 1);
            edges[indexTo].insert(edge2);
        }
    }

    void Graph::connect() {
        for (int i = 0; i < words->length(); i++) {
            for (int j = i; j < words->length(); j++) {
                if (i == j) {
                    continue;
                } else {
                    addEdge(words[i], words[j]);
                }
            }
        }
    }

    int Graph::findIndex(std::string s) {
        int result;
        int diffCount = 0;
        for (int i = 0; i < wordNumber; i++) {
            if (s.length() == words[i].length()) {
                for (int j = 0; j < s.length(); j++) {
                    if (s[j] != words[i][j]) {
                        diffCount++;
                    }
                }
            }
            if (diffCount == 0) {
                result = i;
                break;
            }
            diffCount = 0;
        }
        return result;
    }

    void Graph::dijkstra(std::string start, std::string end) {
        int indexStart = findIndex(start);
        int indexEnd = findIndex(end);
        std::string result;

        Path* paths = dijkstra(indexStart);
        Path path = paths[indexEnd];

        while (path.getDistance() != -1) {
            result.insert(0, words[indexEnd] + " ");
            indexEnd = path.getPrevious();
            if (indexEnd == indexStart) {
                result.insert(0, words[indexStart] + " ");
                break;
            }
            path = paths[indexEnd];
        }
        std::cout << result << std::endl;
    }


}