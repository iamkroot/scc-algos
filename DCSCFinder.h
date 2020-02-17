#ifndef DCSCFINDER_H
#define DCSCFINDER_H

#include "Graph.h"
#include <vector>

/**
 * @brief Implements a Divide and Conquer strategy to find the strongly connected components
 * @param g
 */
template<typename T>
std::vector<Graph<T>> getSCC(Graph<T> g);

#endif //DCSCFINDER_H
