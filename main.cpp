#include <iostream>
#include "Graph.h"
#include "DCSCFinder.tcc"
#include "KosarajuFinder.tcc"
#include "Utils.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Provide a file path to a csv containing list of edges." << std::endl;
        return 0;
    } else if (argc > 2) {
        std::cout << "Too many arguments!" << std::endl;
        return 1;
    }

    std::vector<std::pair<int, int>> edgeList;
    edgeList = readEdgeList(argv[1]);
    Graph<int> g{};
    for (const auto &edge : edgeList) {
        g.addEdge(edge.first, edge.second);
    }
    std::cout << "Loaded graph with " << g.getNumVertices() << " vertices and "
              << g.getNumEdges() << " edges." << std::endl;
    auto KosarajuSCC = Kosaraju::getSCC(g);
    std::cout << "Kosaraju: "<< KosarajuSCC.size() << " components." << std::endl;
    auto DCSCC = DCSC::getSCC(g);
    std::cout << "Divide and Conquer: "<< DCSCC.size() << " components." << std::endl;
}
