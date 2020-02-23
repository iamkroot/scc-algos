#ifndef KOSARAJUFINDER_TCC
#define KOSARAJUFINDER_TCC

#include "Graph.h"
#include <vector>

namespace Kosaraju {
    /**
     * @brief Implements Kosaraju's algorithm to find the strongly connected components
     * @param g
     */
    template<typename T>
    std::vector<Graph<T>> getSCC(Graph<T> g) {
        std::vector<Graph<T>> scc;

        std::stack<T> stack;
        UnorderedSet<T> verts = g.getVertices();
        std::unordered_map<T, bool> visited(verts.size());

        for (const auto &vertex : verts)
            visited.insert({vertex, false});

        // Fill vertices in stack according to their finishing times
        for (const auto &items : verts)
            if (visited[items] == false)
                g.fillOrder(items, visited, stack);


        // Mark all the vertices as not visited (For second DFS)
        for (const auto &items : verts)
            visited[items] = false;

        // Now process all vertices in order defined by stack
        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (visited[v] == false) {
                Graph<T> comp;
                g.DFSUtil(v, visited, comp);
                scc.push_back(comp);
            }
        }

        return scc;
    }
}
#endif //KOSARAJUFINDER_TCC
