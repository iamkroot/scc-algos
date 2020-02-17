#include "DCSCFinder.h"

template<typename T>
std::vector<Graph<T>> getSCC(Graph<T> g) {
    std::vector<Graph<T>> scc;
    if (g.getNumEdges() == 0) {
        for (const auto &vertex : g.getVertices()) {
            scc.emplace_back(vertex);  // create single vertex graph using
        }
        return scc;
    }
    auto v = g.getAdjLst().begin()->first;  // select an arbitrary vertex (adjLst is unordered)

    UnorderedSet<T> pred, succ;
    g.getPredecessors(v, pred);
    g.getSuccessors(v, succ);

    auto compVerts = pred & succ;  // the vertices in component of selected vertex
    Graph<T> comp = g.getInducedSubgraph(compVerts);  // the graph for pred ∩ succ
    scc.push_back(comp);

    // recurse on the other parts
    auto remPred = getSCC(g.getInducedSubgraph(pred - compVerts));  // G \ pred
    auto remSucc = getSCC(g.getInducedSubgraph(succ - compVerts));  // G \ succ
    auto rem = getSCC(g.getInducedSubgraph(g.getVertices() - (pred | succ)));  // G \ (pred u succ)

    scc.reserve(scc.size() + remPred.size() + remSucc.size() + rem.size());
    scc.insert(scc.end(), remPred.begin(), remPred.end());
    scc.insert(scc.end(), remSucc.begin(), remSucc.end());
    scc.insert(scc.end(), rem.begin(), rem.end());
    return scc;
}
