import argparse
import csv
import re
import subprocess as sp
from pathlib import Path


def run(exec_path: Path, dataset_dir: Path, results_dir: Path):
    comp_pattern = re.compile(
        r".*?(?P<num_verts>\d+) vertices and (?P<num_edges>\d+) edges.*?"
        r"(?P<num_comps>\d+) components.*?(?P<kosaraju>\d+).*?Time: (?P<dcsc>\d+).*?"
        r"(?P<ratio>\d+(\.\d*)?)",
        re.MULTILINE | re.DOTALL,
    )
    results_dir.mkdir(parents=True, exist_ok=True)
    results = []
    results_file = results_dir / "results.csv"
    for dataset_path in dataset_dir.glob("**/*.csv"):
        rel_path = dataset_path.relative_to(dataset_dir)
        scc_path = (results_dir / rel_path).with_name(dataset_path.stem + "_scc.txt")
        scc_path.parent.mkdir(parents=True, exist_ok=True)
        scc_txt: str = sp.check_output(
            [str(exec_path), "getSCC", str(dataset_path.resolve())], text=True
        )
        scc_path.write_text("\n".join(scc_txt.splitlines()[2:-1]))

        comp_txt: str = sp.check_output(
            [str(exec_path), "compare", str(dataset_path.resolve())], text=True
        )
        match = comp_pattern.search(comp_txt)
        if not match:
            continue
        res = {"dataset": dataset_path.stem}
        res.update(match.groupdict())
        results.append(res)

    with open(results_file, "w") as f:
        w = csv.DictWriter(f, results[0])
        w.writeheader()
        w.writerows(results)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-e",
        "--exec-path",
        type=Path,
        help="Path to compiled executable scc_algos",
        required=True,
    )
    parser.add_argument(
        "-d",
        "--dataset-dir",
        type=Path,
        help="Path to directory which contains input graph CSVs",
        required=True,
    )
    parser.add_argument(
        "-r",
        "--results-dir",
        type=Path,
        help="Path to folder where results should be stored",
        required=True,
    )
    args = parser.parse_args()
    run(args.exec_path, args.dataset_dir, args.results_dir)


if __name__ == '__main__':
    main()
