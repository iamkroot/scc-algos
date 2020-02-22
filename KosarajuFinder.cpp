#include "KosarajuFinder.h"
#include<stack>
#include<vector>

template <typename T>
std::vector<Graph<T>> getKSCC(Graph<T> g) {
    std::vector<Graph<T>> scc;

    std::stack<T> Stack; 
    UnorderedSet<T> verts = g.getVertices();
    // Mark all the vertices as not visited (For first DFS) 
    std::unordered_map<T,bool> visited;

    for(const auto &items : verts) 
        visited.insert(items, false); 
  
    // Fill vertices in stack according to their finishing times 
    for(const auto &items : verts) 
        if(visited[items] == false) 
            fillOrder(items, visited, Stack); 
  
  
    // Mark all the vertices as not visited (For second DFS) 
    for(const auto &items : verts) 
        visited[items] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
            Graph<T> comp;
            g.DFSUtil(v, visited,comp); 
            scc.push_back(comp);
        } 
    } 

    return scc;
}
