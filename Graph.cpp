#include "Graph.h"

Graph::Graph() = default;

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
    auto max = std::max(u, v);
    if (adjLst.size() < max) {
        adjLst.resize(max);
        backAdjLst.resize(max);
    }
    adjLst[u].push_back(v);
    backAdjLst[v].push_back(u);
}

std::vector<int> Graph::getSuccessors(int vertex) const {
    return adjLst[vertex];
}

std::vector<int> Graph::getPredecessors(int vertex) const {
    return backAdjLst[vertex];
}
