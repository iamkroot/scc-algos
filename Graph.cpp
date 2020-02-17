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
void Graph<T>::addVertex(T v) {
    if (not adjLst.contains(v))
        adjLst[v] = std::unordered_set<T>();
    if (not backAdjLst.contains(v))
        backAdjLst[v] = std::unordered_set<T>();
}

template<typename T>
void Graph<T>::addEdge(T u, T v) {
    addVertex(u);
    addVertex(v);
    adjLst[u].insert(v);
    backAdjLst[v].insert(u);
    numEdges++;
}

template<typename T>
int Graph<T>::getNumEdges() const {
    return numEdges;
}

template<typename T>
int Graph<T>::getNumVertices() const {
    return adjLst.size();
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

template<typename T>
Graph<T>::Graph(T v) {
    addVertex(v);
}

template
class Graph<int>;

template
class Graph<char>;

template
class Graph<std::string>;
