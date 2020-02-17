#include "DCSCFinder.h"
#include <unordered_set>

std::unordered_set<int> getAncestors(Graph g, int v) {
    auto directPredecessors = g.getPredecessors(v);
    std::unordered_set<int> ancestors(directPredecessors.begin(), directPredecessors.end());
    for (const auto &vertex : directPredecessors) {
        ancestors.merge(getAncestors(g, vertex));
    }
    return ancestors;
}

std::unordered_set<int> getDescendants(Graph g, int v) {
    auto directSuccessors = g.getSuccessors(v);
    std::unordered_set<int> successors(directSuccessors.begin(), directSuccessors.end());
    for (const auto &vertex : directSuccessors) {
        successors.merge(getDescendants(g, vertex));
    }
    return successors;
}

std::vector<Graph> getSCC(Graph g) {
    if (g.numEdges() == 0) {
        return std::vector<Graph> (g.numVertices(), Graph(1));
    }
    int v = std::rand() % g.numVertices();
    Graph scc;
}
