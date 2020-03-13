# Finding Strongly Connected Components in a DiGraph

Implementation and visualization of algorithms to find Strongly Connected Components in a Directed Graph.

## Algorithms Implemented

* [Divide-and-Conquer Algorithm](https://www.researchgate.net/publication/229023670_A_divide-and-conquer_algorithm_for_identifying_strongly_connected_components) with runtime *O(ElogV)*

* [Kosaraju's Algorithm (Classical)](https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm) - with runtime *Θ(V + E)*

where V = number of vertices, E = number of edges in the given graph

## Vizualization

Vizualization Library - [ElGrapho](https://www.elgrapho.com/)

[Here](./viz/graph_viz.html) is the generated html page with some preloaded datasets. (Download the entire [`viz`](./viz/) folder)

## Results
The datasets for large graphs have been taken from [this](https://snap.stanford.edu/data/) page.

dataset|num_verts|num_edges|num_comps|dcsc (μs)|kosaraju (μs)|ratio
-|-|-|-|-|-|-
bitcoin|5882|35593|1145|1363632|64964|20.9906
facebook|4039|88234|4039|1991472|52247|38.1165
wiki-votes|7115|103689|5816|17753306|74924|236.951

## Running
### Main
The project uses a cmake build system and targets C++ 20. After compilation using cmake, the executable can be run from the terminal:
```
Usage:
scc_algos [compare|getSCC] DATASET_PATH [DATASET_PATH...]

compare  For each graph, measure the runtimes of Kosaraju and Divide and Conquer algorithms
getSCC   For each graph, print the vertices Strongly Connected Components to stdout

The DATASET_PATH should be a path (not containing spaces) to a CSV file with edges of the graph in the form: src,dest
```

### Batch
The [`run.py`](./run.py) script automates this task for when you have lots of datasets and would like to run the algorithms for each of them. 
```
Usage:
  -e EXEC_PATH,   --exec-path EXEC_PATH
                        Path to compiled executable scc_algos
  -d DATASET_DIR, --dataset-dir DATASET_DIR
                        Path to directory which contains input graph CSVs
  -r RESULTS_DIR, --results-dir RESULTS_DIR
                        Path to folder where results should be stored
```
This will also create a `results.csv` similar to the table in [Results](#results) section.

### Viz
[`viz.py`](./viz/viz.py) script has been made to format the graph data as required by ElGrapho.
```
Usage:
-d DATASET_DIR, --dataset-dir DATASET_DIR
                      Path to directory which contains input graph CSVs
-r RESULTS_DIR, --results-dir RESULTS_DIR
                      Path to folder where graph SCCs are stored
-o OUTPUT_JS, --output-js OUTPUT_JS
                      Path to JS file which will contain the graph models (default: graph_data.js)
```

## Authors

1. 2017A7PS0184H Krut Patel
2. 2017A7PS0130H Niral Khambhati
3. 2017A7PS1722H Arnav Buch
4. 2017A7PS0137H Shantanu Gupta