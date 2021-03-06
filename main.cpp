#include <iostream>
#include <sstream>
#include "Graph.h"
#include "DCSCFinder.tcc"
#include "KosarajuFinder.tcc"
#include "Utils.h"

/**
 * @brief Read graph from file
 * @param path File path
 * @return Graph class 
 */
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

/**
 * @brief Compare Divide and Conquer Algo with Kosaraju Algo
 * @param g Graph to run both the algorithms on
 */
void compareAlgos(const Graph<int> &g) {
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

/**
 * @brief Output number of Strongly Connected Components
 * @param scc All the Strongly Connected Components
 */
void writeSCC(const std::vector<UnorderedSet<int>> &scc) {
    std::cout << "Number of components: " << scc.size() << std::endl;
    int i = 1;
    unsigned long max_size = 0;
    for (const auto &comp : scc) {
        for (const auto &vert: comp) {
            std::cout << vert << " ";
        }
        std::cout << std::endl;
        i++;
        max_size = std::max(max_size, comp.size());
    }
    std::cout << "Largest component has " << max_size << "vertices" << std::endl;
}

int main(int argc, char *argv[]) {
    std::stringstream help;
    help << "Usage:" << std::endl
         << "scc_algos [compare|getSCC] DATASET_PATH [DATASET_PATH...]" << std::endl
         << std::endl
         << "compare\t For each graph, measure the runtimes of Kosaraju and Divide and Conquer algorithms"
         << std::endl
         << "getSCC\t For each graph, print the vertices Strongly Connected Components to stdout" << std::endl
         << std::endl
         << "The DATASET_PATH should be a path (no spaces) to a CSV file containing edges of the graph in the form: src,dest"
         << std::endl;

    if (argc < 2) {
        std::cout << help.str();
        return 0;
    }
    std::string op = argv[1];
    if (op != "compare" && op != "getSCC") {
        std::cerr << help.str();
        return -1;
    }
    for (int i = 2; i < argc; ++i) {
        auto g = readGraph(argv[i]);
        if (g.getNumVertices() == 0) {
            continue;
        }
        if (op == "compare") {
            compareAlgos(g);
        } else if (op == "getSCC") {
            writeSCC(Kosaraju::getSCC(g));
        }
    }
}
