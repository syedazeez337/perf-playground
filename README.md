# ⚡ perf-playground

**A collection of small, focused experiments in performance benchmarking, SIMD, and parallel computing.**  
The goal is to build one component at a time, measure it carefully, and document results in a transparent, reproducible way.

---

## 📂 Repository Structure

```

perf-playground/
├── components/               # self-contained components (one per topic)
│   └── 01\_factorial\_baseline # recursion vs iteration factorial benchmarks
│       ├── bench/            # binaries + temp files (gitignored)
│       ├── results/          # committed CSVs, plots, env info
│       ├── Makefile          # local build rules for this component
│       └── README.md         # explanation + results for this component
├── scripts/                  # utility scripts
│   ├── cpu\_info.sh           # captures CPU/GPU/OS/compiler info
│   └── run\_bench.sh          # entrypoint to build + run a component
├── toolchain.mk              # shared compiler flags
└── README.md                 # (this file)

````

Each **component** has its own:
- `README.md` (purpose, how to run, results, discussion)
- `bench/` (build outputs)
- `results/` (CSV/plots/env)

---

## 🧩 Components

- **01_factorial_baseline**  
  Compare **recursive**, **iterative**, and **iterative-safe** factorial implementations.  
  Measure performance, correctness, and overflow boundaries.  
  → [See component README](./components/01_factorial_baseline/README.md)

(Future components will explore batch APIs, SIMD chunking, parallel CPU, GPU, Stirling approximation, prime factorization, etc.)

---

## 🚀 How to Run

1. Clone the repo:
   ```bash
   git clone https://github.com/syedazeez337/perf-playground.git
   cd perf-playground
   ```

2. Capture environment info:

   ```bash
   ./scripts/cpu_info.sh > components/01_factorial_baseline/results/env.txt
   ```

3. Run a component benchmark:

   ```bash
   ./scripts/run_bench.sh 01_factorial_baseline
   ```

4. Results (CSV + summary) will appear under the component’s `results/` folder.

---

## 📊 Reporting Style

* **Correctness first:** cross-check against LUTs, check overflow boundaries.
* **Reproducibility:** all CSVs, env info, and median/p95 summaries are committed.
* **Visualization:** plots (when relevant) included in `results/` and linked in the component README.
* **Discussion:** short notes on why one variant outperforms another.

---

## 🔧 System Info

All experiments are developed & run on:

* **CPU:** Intel 13th Gen i5-13450HX (8C/12T, AVX2)
* **RAM:** 16 GB
* **GPU:** NVIDIA GeForce RTX 3050 (6 GB, compute capability 8.6)
* **OS:** Ubuntu (rolling updates)

---

## 📅 Roadmap

* [ ] 01 – Factorial Baseline (recursive vs iterative vs safe)
* [ ] 02 – Factorial Batch API (prep for SIMD)
* [ ] 03 – SIMD Chunked Products (AVX2)
* [ ] 04 – Parallel CPU (OpenMP/pthreads)
* [ ] 05 – Stirling Approximation vs Exact
* [ ] 06 – Prime Factor Powers (Legendre’s formula)
* [ ] 07 – GPU Partial Products (CUDA/OpenCL)

---
