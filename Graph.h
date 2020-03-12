#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include<stack>
#include "UnorderedSet.h"

template<typename T>
using AdjLst = std::unordered_map<T, UnorderedSet<T>>;

/**
 * @class Graph
 * @brief Representation of a directed graph as adjacency list
 */
template<typename T>
class Graph {
    int numEdges{0};
    AdjLst<T> adjLst;
    AdjLst<T> backAdjLst;
public:
    /**
     * @brief Initialize an empty graph
     */
    Graph();

    /**
     * @brief Get adjacency list of the graph
     * @return Adjacency list
     */
    const AdjLst<T> &getAdjLst() const;

    /**
     * @brief Get back adjacency list of the graph
     * @return Back adjacency list
     */
    const AdjLst<T> &getBackAdjLst() const;

    /**
     * @brief Add a vertex to the graph
     * @param v Vertex to be added
     */
    void addVertex(T v);

    /**
     * @brief Add an edge to the graph
     * @param u One of the vertices forming the edge 
     * @param v Another vertex forming the edge
     */
    void addEdge(T u, T v);

    /**
     * @brief Get the number of edges in the graph
     * @return Number of edges in the graph
     */
    [[nodiscard]] int getNumEdges() const;
    
    /**
     * @brief Get the number of vertices in the graph
     * @return Number of vertices in the graph
     */
    [[nodiscard]] int getNumVertices() const;

    /**
     * @brief Get all vertices in the Graph 
     * @return An Unordered Set containing all the vertices of the graph
     */
    UnorderedSet<T> getVertices() const;

    /**
     * @brief Find all the vertices that given vertex can be reached from
     * @param v Vertex to be reached
     * @param predecessors The output set of vertices
     */
    void getPredecessors(T v, UnorderedSet<T> &predecessors);

    /**
     * @brief Find all the vertices that can be reached from the given vertex
     * @param v Vertex
     * @param successors The output set of vertices
     */
    void getSuccessors(T v, UnorderedSet<T> &successors);

    /**
     * @brief Return a new subgraph with edges only between the given set of vertices
     * @param vertices Vertices in the subgraph
     * @return
     */
    Graph<T> getInducedSubgraph(const UnorderedSet<T> &vertices);

    /**
     * @brief Fill the stack in the visited order
     * @param v New node to fill 
     * @param visited Visited array (for traversal)
     * @param stack Stack to fill in-order
     */
    void fillOrder(T v, std::unordered_map<T,bool> &visited, std::stack<T> &stack);

    /**
     * @brief Do a DFS on the given graph recursively
     * @param v Current vertex reached
     * @param visited Visited array
     * @param comp Graph made by DFS till the current vertex
     */
    void DFSUtil(T v, std::unordered_map<T,bool> &visited, UnorderedSet<T> &comp);
};

#endif //GRAPH_H
 
