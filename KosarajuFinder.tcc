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

        for (const auto &items : verts)
            if (visited[items] == false)
                g.fillFinish(items, visited, stack);

        for (const auto &items : verts)
            visited[items] = false;

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (visited[v] == false) {
                Graph<T> comp;
                g.DFS(v, visited, comp);
                scc.push_back(comp);
            }
        }

        return scc;
    }
}
#endif //KOSARAJUFINDER_TCC
