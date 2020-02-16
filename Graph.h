#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

/**
 * @brief Representation of a directed graph as adjacency list
 */
class Graph {
    std::vector<std::vector<int>> adjLst;
public:
    explicit Graph(int numVertices);

    [[nodiscard]] int numVertices() const;
    [[nodiscard]] int numEdges() const;
    void addEdge(int u, int v);

    [[nodiscard]] const std::vector<std::vector<int>> &getAdjLst() const;

    [[nodiscard]] std::vector<int> getNeighbors(int vertex) const;
};

#endif //GRAPH_H
