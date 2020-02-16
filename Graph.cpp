#include "Graph.h"

Graph::Graph(int numVertices) {
    adjLst.resize(numVertices);
}

const std::vector<std::vector<int>> &Graph::getAdjLst() const {
    return adjLst;
}
