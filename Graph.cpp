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
        adjLst[v] = UnorderedSet<T>();
    if (not backAdjLst.contains(v))
        backAdjLst[v] = UnorderedSet<T>();
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
void Graph<T>::getPredecessors(T v, UnorderedSet<T> &predecessors) {
    if (predecessors.contains(v))
        return;
    predecessors.insert(v);
    for (const auto &predecessor : backAdjLst[v]) {
        getPredecessors(predecessor, predecessors);
    }
}

template<typename T>
void Graph<T>::getSuccessors(T v, UnorderedSet<T> &successors) {
    if (successors.contains(v))
        return;
    successors.insert(v);
    for (const auto &successor : adjLst[v]) {
        getPredecessors(successor, successors);
    }
}

template<typename T>
Graph<T>::Graph(T v) {
    addVertex(v);
}

template<typename T>
UnorderedSet<T> Graph<T>::getVertices() const {
    UnorderedSet<T> verts;
    for (const auto &items : adjLst) {
        verts.insert(items.first);
    }
    return verts;
}

template<typename T>
Graph<T> Graph<T>::getInducedSubgraph(const UnorderedSet<T> &vertices) {
    Graph<T> subgraph;
    for (const auto &vertex : vertices) {
        subgraph.addVertex(vertex);
        for (const auto &v : adjLst[vertex]) {
            if (vertices.contains(v)) {
                subgraph.addEdge(vertex, v);
            }
        }
    }
    return subgraph;
}
template<typename T>
void Graph<T>::fillOrder(T v, std::unordered_map<T,bool> &visited, std::stack<T> &Stack) 
{ 
    visited[v] = true; 
  
    
    for(const auto &item : adjLst[v]) 
        if(!visited[item]) 
            fillOrder(item, visited, Stack);
 
    Stack.push(v); 
} 

template<typename T>
void Graph<T>::DFSUtil(T v, std::unordered_map<T,bool> &visited, Graph<T> &comp) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    comp.addVertex(v); 
  
    // Recur for all the vertices adjacent to this vertex 
    for (const auto &item : backAdjLst[v]) 
        if (!visited[item]) 
            DFSUtil(item, visited, comp); 
} 
template
class Graph<int>;

template
class Graph<char>;

template
class Graph<std::string>;
