#include <iostream>
#include "Graph.h"
#include "DCSCFinder.tcc"
#include "KosarajuFinder.tcc"
#include "Utils.h"

Graph<int> readGraph(const std::string &path) {
    std::vector<std::pair<int, int>> edgeList;
    try {
        edgeList = readEdgeList(path);
    } catch (std::runtime_error &err) {
        std::cerr << "Error parsing " << path << std::endl << err.what() << std::endl;
        return {};
    }
    Graph<int> g{};
    for (const auto &edge : edgeList) {
        g.addEdge(edge.first, edge.second);
    }
    std::cout << "Loaded graph from " << path << " with " << g.getNumVertices() << " vertices and "
              << g.getNumEdges() << " edges." << std::endl;
    return g;
}

void compareAlgos(const Graph<int>& g) {
    Stopwatch<> stopwatch;
    auto KosarajuSCC = Kosaraju::getSCC(g);
    auto KosarajuTime = stopwatch.stop();
    std::cout << "Kosaraju: " << KosarajuSCC.size() << " components. Time: " << KosarajuTime << "μs." << std::endl;

    stopwatch.start();
    auto DCSCC = DCSC::getSCC(g);
    auto DCSCTime = stopwatch.stop();
    std::cout << "Divide and Conquer: " << DCSCC.size() << " components. Time: " << DCSCTime << "μs." << std::endl;

    std::cout << "Runtime ratio: " << (double) DCSCTime / KosarajuTime << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Provide a file path to a csv containing list of edges." << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        auto g = readGraph(argv[i]);
        if (g.getNumVertices() == 0) {
            continue;
        }
        compareAlgos(g);
    }
}
