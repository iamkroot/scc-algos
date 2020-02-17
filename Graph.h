#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>

template<typename T>
using AdjLst = std::unordered_map<T, std::unordered_set<T>>;

/**
 * @brief Representation of a directed graph as adjacency list
 */
template<typename T>
class Graph {
    int numEdges{0};
    AdjLst<T> adjLst;
    AdjLst<T> backAdjLst;
public:
    Graph();

    explicit Graph(T v);

    const AdjLst<T> &getAdjLst() const;

    const AdjLst<T> &getBackAdjLst() const;

    void addVertex(T v);

    void addEdge(T u, T v);

    [[nodiscard]] int getNumEdges() const;

    [[nodiscard]] int getNumVertices() const;

    std::unordered_set<T> getPredecessors(T v);

    std::unordered_set<T> getSuccessors(T v);
};

#endif //GRAPH_H
