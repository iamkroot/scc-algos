#include "Graph.h"

Graph::Graph(int numVertices) {
    adjLst.resize(numVertices);
}

const std::vector<std::vector<int>> &Graph::getAdjLst() const {
    return adjLst;
}

int Graph::numVertices() const {
    return adjLst.size();
}

int Graph::numEdges() const {
    int size = 0;
    for (const auto &lst : adjLst) {
        size += lst.size();
    }
    return size;
}

void Graph::addEdge(int u, int v) {
    adjLst[u].push_back(v);
}

std::vector<int> Graph::getNeighbors(int vertex) const {
    return adjLst[vertex];
}
