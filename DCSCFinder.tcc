/**
 * @file DCSCFinder.tcc
 * @brief Implementation of Divide-and-Conquer Strongly Connected (DCSC) Algorithm for finding strongly connected compenents in a directed graph
 */
#ifndef DCSCFINDER_TCC
#define DCSCFINDER_TCC

#include "Graph.h"
#include <vector>
#include <random>

namespace DCSC {
    /**
     * @brief Implements a Divide and Conquer strategy to find the strongly connected components
     * @param g Graph to find scc from
     */
    template<typename T>
    std::vector<UnorderedSet<T>> getSCC(Graph<T> g) {
        std::vector<UnorderedSet<T>> scc;
        if (g.getNumEdges() == 0) {
            for (const auto &vertex : g.getVertices()) {
                UnorderedSet<T> comp;
                comp.insert(vertex);
                scc.push_back(comp);  // create single vertex graph using
            }
            return scc;
        }
        auto vi = g.getAdjLst().begin();
        std::advance(vi, std::random_device()() % g.getNumVertices());
        auto v = vi->first;  // select an arbitrary vertex

        UnorderedSet<T> pred, succ;
        g.getPredecessors(v, pred);
        g.getSuccessors(v, succ);

        auto compVerts = pred & succ;  // the vertices in component of selected vertex
        scc.push_back(compVerts);

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
}

#endif //DCSCFINDER_TCC
