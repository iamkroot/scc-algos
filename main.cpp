#include <iostream>
#include "Graph.h"
#include "DCSCFinder.cpp"

int main() {
    auto g = Graph<char>();
    g.addVertex('f');
    g.addVertex('a');
    g.addVertex('b');
    for (const auto &items : getSCC(g)) {
        std::cout << items.getNumVertices() << std::endl;
    }

}
