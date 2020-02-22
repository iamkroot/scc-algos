#include <iostream>
#include "Graph.h"
// #include "DCSCFinder.cpp"
#include "KosarajuFinder.cpp"

int main() {
    auto g = Graph<int>();
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
    for (const auto &items : getKSCC(g)) {
        std::cout << items.getNumVertices() << std::endl;
    }

}
