#include "DCSCFinder.h"

template<typename T>
std::vector<Graph<T>> getSCC(Graph<T> g) {
    std::vector<Graph<T>> scc;
    if (g.getNumEdges() == 0) {
        for (const auto &items : g.getAdjLst()) {
            scc.emplace_back(items.first);
        }
        return scc;
    }
    return scc;
}
