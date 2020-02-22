#ifndef KOSARAJUFINDER_H
#define KOSARAJUFINDER_H

#include "Graph.h"
#include<vector>

/**
 * @brief Implements Kosaraju's algorithm to find the strongly connected components
 * @param g
 */
template<typename T>
std::vector<Graph<T>> getKSCC(Graph<T> g);

#endif //KOSARAJUFINDER_H
