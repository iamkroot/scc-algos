from pathlib import Path
import csv
import argparse


def read_graph_csv(file: Path):
    nodes = set()
    edges = []
    with open(file) as f:
        reader = csv.reader(f, delimiter="\t")
        for row in reader:
            nodes.add(int(row[0]))
            nodes.add(int(row[1]))
            edges.append((int(row[0]), int(row[1])))
    return tuple(sorted(nodes)), tuple(edges)


def write_elgrapho(inp_file: Path, out_file: Path):
    nodes, edges = read_graph_csv(inp_file)

    node_map = {label: i for i, label in enumerate(nodes)}
    nodes_fmt = "{{group: 0, label: {}}}"
    nodes_str = ",\n\t\t".join(nodes_fmt.format(node) for node in nodes)

    edges_fmt = "{{from: {}, to: {}}}"
    edges_str = ",\n\t\t".join(
        edges_fmt.format(node_map[u], node_map[v]) for u, v in edges
    )

    js_str = f"""var model = {{
    nodes: [
        {nodes_str}
    ],
    edges: [
        {edges_str}
    ],
    steps: 30
}};"""
    out_file.write_text(js_str)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--dataset-path", type=Path, required=True)
    parser.add_argument("--elgrapho-js-path", type=Path, required=True)
    args = parser.parse_args()
    write_elgrapho(args.dataset_path, args.elgrapho_js_path)


if __name__ == '__main__':
    main()
