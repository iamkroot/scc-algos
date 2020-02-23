#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include<stack>
#include "UnorderedSet.h"

template<typename T>
using AdjLst = std::unordered_map<T, UnorderedSet<T>>;

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

    UnorderedSet<T> getVertices() const;

    /**
     * @brief Find all the vertices that given vertex can be reached from
     * @param v
     * @param predecessors The output set of vertices
     */
    void getPredecessors(T v, UnorderedSet<T> &predecessors);

    /**
     * @brief Find all the vertices that can be reached from the given vertex
     * @param v
     * @param successors The output set of vertices
     */
    void getSuccessors(T v, UnorderedSet<T> &successors);

    /**
     * @brief Return a new subgraph with edges only between the given set of vertices
     * @param vertices The vertices in the subgraph
     * @return
     */
    Graph<T> getInducedSubgraph(const UnorderedSet<T> &vertices);

    /**
     * @brief Fill the stack according to finishing times
     * @param v Vertices in the graph
     * @param visited The map containing status of visit of a vertex
     * @param Stack The stack containing vertices in order of finishing times
     * @return
     */
    void fillFirst(T v, std::unordered_map<T,bool> &visited, std::stack<T> &Stack);

    /**
     * @brief Run DFS for the transpose of the graph
     * @param v Vertices in the graph
     * @param visited The map containing status of visit of a vertex        
     * @param comp The graph for a connected component
     * @return
     */
    void DFS(T v, std::unordered_map<T,bool> &visited, Graph<T> &comp);
};

#endif //GRAPH_H
