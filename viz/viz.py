from pathlib import Path
import csv
import argparse


def read_graph_csv(file: Path):
    nodes = set()
    edges = []
    with open(file) as f:
        reader = csv.reader(f)
        for row in reader:
            u, v = map(int, row)
            nodes.add(u)
            nodes.add(v)
            edges.append((u, v))
    return tuple(sorted(nodes)), tuple(edges)


def read_scc(file: Path):
    with open(file) as f:
        text = f.readlines()
    return {v: i for i, line in enumerate(text, 1) for v in map(int, line.split())}


def get_graph_model(name, nodes, edges, scc):
    node_map = {label: i for i, label in enumerate(nodes)}
    nodes_fmt = "{{group: {}, label: {}}}"
    nodes_str = ",".join(nodes_fmt.format(scc[node], node) for node in nodes)

    edges_fmt = "{{from: {}, to: {}}}"
    edges_str = ",".join(edges_fmt.format(node_map[u], node_map[v]) for u, v in edges)

    return f'{{name: "g_{name}", nodes: [{nodes_str}], edges: [{edges_str}]}}'


def write_elgrapho(dataset_dir: Path, results_dir: Path, out_file: Path):
    graph_models = []
    for dataset_path in dataset_dir.glob("**/*.csv"):
        rel_path = dataset_path.relative_to(dataset_dir)
        scc_path = (results_dir / rel_path).with_name(dataset_path.stem + "_scc.txt")

        nodes, edges = read_graph_csv(dataset_path)
        scc = read_scc(scc_path)
        graph_models.append(get_graph_model(dataset_path.stem, nodes, edges, scc))
    js_str = f"""var models = [{",".join(graph_models)}];"""
    out_file.write_text(js_str)


def main():
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )
    parser.add_argument(
        "-d",
        "--dataset-dir",
        type=Path,
        required=True,
        help="Path to directory which contains input graph CSVs",
    )
    parser.add_argument(
        "-r",
        "--results-dir",
        type=Path,
        required=True,
        help="Path to folder where graph SCCs are stored",
    )
    parser.add_argument(
        "-o",
        "--output-js",
        default="graph_data.js",
        type=Path,
        required=True,
        help="Path to JS file which will contain the graph models",
    )
    args = parser.parse_args()
    write_elgrapho(args.dataset_path, args.results_dir, args.output_js)


if __name__ == '__main__':
    main()
