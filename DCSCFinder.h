#ifndef DCSCFINDER_H
#define DCSCFINDER_H

#include "SCCFinder.h"

/**
 * @brief Implements a Divide and Conquer strategy to find the strongly connected components
 */
class DCSCFinder : SCCFinder {
public:
    std::vector<Graph> getSCC(Graph g) override;
};

#endif //DCSCFINDER_H
