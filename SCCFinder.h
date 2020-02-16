#ifndef SCCFINDER_H
#define SCCFINDER_H

#include "Graph.h"

/**
 * @brief Abstract interface that should be implemented by algorithms for finding the Strongly Connected Components
 */
class SCCFinder {
public:
    virtual ~SCCFinder() = default;

    /**
     * @brief Find all the Strongly Connected Components
     * @param g The input graph
     * @return Vector of graphs representing the components
     */
    virtual std::vector<Graph> getSCC(Graph g) = 0;
};

#endif //SCCFINDER_H
