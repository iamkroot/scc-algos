#include <iostream>
#include "Graph.h"
#include "DCSCFinder.tcc"
#include "KosarajuFinder.tcc"

int main() {
    auto g = Graph<int>();
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    for (const auto &items : DCSC::getSCC(g)) {
        std::cout << items.getNumVertices() << std::endl;
    }
    for (const auto &items : Kosaraju::getSCC(g)) {
        std::cout << items.getNumVertices() << std::endl;
    }

}
