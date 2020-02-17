#include "Graph.h"

template<typename T>
Graph<T>::Graph() = default;

template<typename T>
const AdjLst<T> &Graph<T>::getAdjLst() const {
    return adjLst;
}

template<typename T>
const AdjLst<T> &Graph<T>::getBackAdjLst() const {
    return backAdjLst;
}

template<typename T>
void Graph<T>::addEdge(T u, T v) {
    adjLst[u].insert(v);
    backAdjLst[v].insert(u);
}

template<typename T>
std::unordered_set<T> Graph<T>::getPredecessors(T v) {
    std::unordered_set<T> predecessors = backAdjLst[v];
    for (const auto &predecessor : backAdjLst[v]) {
        predecessors.merge(getPredecessors(predecessor));
    }
    return predecessors;
}

template<typename T>
std::unordered_set<T> Graph<T>::getSuccessors(T v) {
    std::unordered_set<T> successors = adjLst[v];
    for (const auto &successor : adjLst[v]) {
        successors.merge(getPredecessors(successor));
    }
    return successors;
}
