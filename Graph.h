#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
    std::vector<std::vector<int>> adjLst;
public:
    explicit Graph(int numVertices);

    int numVertices() const;
    int numEdges() const;
    void addEdge(int u, int v);

    const std::vector<std::vector<int>> &getAdjLst() const;

    std::vector<int> getNeighbors(int vertex) const;
};

#endif //GRAPH_H
