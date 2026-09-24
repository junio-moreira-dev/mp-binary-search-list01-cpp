# Programming Marathon — Paradigms — List 01

Practice exercises for **Programming Marathon** — problems based on **Binary Search on the Answer** and greedy validation.

> Instituto Federal do Triângulo Mineiro — Campus Patrocínio
> Course: Technology in Systems Analysis and Development
> Unit: Programming Marathon
> Instructors: Daniele Oliveira | Júnio Moreira
> Date: 24/09/2026

---

## 📁 Project Structure

```text
maratona-paradigmas-list01-cpp/
├── src/
│   ├── Exer01_AjudeSeuMadruga.cpp
│   └── Exer02_TransportePaineisSolares.cpp
├── .gitignore
├── CMakeLists.txt
├── main.cpp
├── README.md
├── External Libraries
└── Scratches and Consoles
```

> `External Libraries` and `Scratches and Consoles` are CLion/IntelliJ-generated project-view entries (not real folders tracked in the repository). They can be ignored when browsing the source on disk.

Each `.cpp` file is **standalone** and contains its own `main()` function.

---

## 📝 Exercises

| # | File                                  | Problem                                                            | Main Technique                                  | Complexity     |
| - | ------------------------------------- | ------------------------------------------------------------------ | ----------------------------------------------- | -------------- |
| 1 | `Exer01_AjudeSeuMadruga.cpp`          | Find the cutting height that produces the requested remaining area | Binary Search on the Answer                     | O(N log C / ε) |
| 2 | `Exer02_TransportePaineisSolares.cpp` | Minimize the maximum truck load while preserving panel order       | Binary Search on the Answer + Greedy Validation | O(N log S)     |

<details>
<summary><strong>1. Ajude Seu Madruga</strong></summary>

### Source

*beecrowd #1912 — Paradigmas*

### Problem

Seu Madruga receives `N` rectangular paper strips, each with a width of 1 cm and a given length.

The strips are placed side by side with their bases aligned. A single straight horizontal cut must be made at height `H` so that the total area of the portions above the cut is exactly `A cm²`.

The goal is to determine the cutting height `H`.

### Input

Each test case begins with:

* `N` — number of strips;
* `A` — desired remaining area.

The next line contains the `N` strip lengths.

Constraints:

```text
1 ≤ N ≤ 10^5
1 ≤ A ≤ 10^9
1 ≤ Ci ≤ 10^4
```

The input terminates with:

```text
0 0
```

This test case must not be processed.

### Output

For each test case:

* Print the cutting height `H` with exactly **4 decimal places**.
* Print `:D` if no cut is necessary.
* Print `-.-` if obtaining the requested area is impossible.

### Example

```text
Input
5 3
5 3 6 2 3
4 14
2 5 2 5
0 0
```

```text
Output
4.0000
:D
```

### Algorithm

For a candidate cutting height `mid`, the area remaining above the cut is:

```text
sum(max(Ci - mid, 0))
```

This function is monotonic:

* If `mid` increases, the remaining area decreases.
* If `mid` decreases, the remaining area increases.

Therefore, we can use **Binary Search on the Answer**.

```text
low = 0
high = maximum strip height

while high - low > epsilon:

    mid = (low + high) / 2

    currentArea = calculateCurrentArea(mid)

    if currentArea > targetArea:
        increase the cutting height
        low = mid

    else:
        decrease the cutting height
        high = mid
```

The final value is the cutting height that produces the requested area within the required precision.

### Key Idea

The important observation is that we are not searching for an element in the input.

We are searching for an **answer** — the cutting height.

For each possible height, we can determine whether the resulting area is:

```text
greater than the target
equal to the target
less than the target
```

This creates a monotonic relationship that allows Binary Search to be applied.

</details>

<br>

<details>
<summary><strong>2. Transporte de Painéis Solares</strong></summary>

### Source

*beecrowd #1579 — Paradigmas*

### Problem

A transport company must move solar panels using a limited number of trucks.

The panels must be transported **in the same order in which they appear in the input**. Each truck receives a contiguous sequence of panels.

The freight cost is calculated using:

```text
heaviest truck load × number of trucks used × freight rate
```

The objective is to determine the minimum possible maximum truck load and the corresponding total freight cost.

### Input

The first line contains:

```text
N
```

representing the number of test cases.

Each test case contains:

```text
nPanels trucks freight
```

followed by the weights of the panels.

Constraints:

```text
4 ≤ nPanels ≤ 100
1 ≤ trucks ≤ 10
1 ≤ freight ≤ 50
1 ≤ weight ≤ 1000
```

The order of the panels must be preserved.

### Output

For each test case, print:

```text
maximum truck load total freight
```

The total freight is:

```text
maximum truck load × trucks used × freight
```

### Example

```text
Input
4
5 2 1
20 25 30 40 45
9 3 10
20 10 30 40 50 60 90 80 70
10 4 5
65 10 15 14 70 95 65 25 26 35
4 3 1
23 45 77 90
```

```text
Output
85 $170
150 $4500
151 $3020
235 $235
```

### Algorithm

The problem can be solved using **Binary Search on the Answer**.

The value being searched is:

```text
maximum allowed weight per truck
```

The search interval is:

```text
low  = maximum individual panel weight
high = sum of all panel weights
```

For each candidate `mid`, use a **greedy validation** to determine how many trucks are required.

```text
currentWeight = 0
trucksUsed = 1

for each panel:

    if panel > mid:
        solution is impossible

    if currentWeight + panel > mid:
        open a new truck
        trucksUsed++

    add panel to current truck
```

If:

```text
trucksUsed <= availableTrucks
```

then `mid` is a valid maximum load.

We can try a smaller value:

```text
high = mid - 1
```

Otherwise, we need a larger weight limit:

```text
low = mid + 1
```

The binary search therefore finds the **minimum possible maximum truck load**.

### Key Idea

Again, we are not searching directly for an element of the array.

We are searching for the smallest possible **maximum truck capacity**.

For each candidate capacity, the greedy algorithm tells us whether the panels can be transported using the available trucks.

This creates a monotonic condition:

```text
capacity too small
       ↓
not enough trucks
       ↓
invalid
```

and:

```text
capacity large enough
       ↓
number of trucks ≤ available trucks
       ↓
valid
```

Binary Search is then used to find the first valid capacity.

</details>

---

## 🔎 Key Paradigm

Both exercises use the same high-level idea:

```text
                 Binary Search
                      on
                  the Answer
                       │
             ┌─────────┴─────────┐
             │                   │
       Exercise 1           Exercise 2
             │                   │
       Cutting Height       Truck Capacity
             │                   │
       Area calculation      Greedy validation
```

The important difference is how a candidate answer is validated.

### Exercise 1

For a candidate height:

```text
mid
```

calculate the resulting area:

```text
currentArea = Σ max(Ci - mid, 0)
```

and compare it with the target area.

### Exercise 2

For a candidate truck capacity:

```text
mid
```

simulate the transportation greedily and count how many trucks are necessary.

---

## 🚀 Running in CLion

1. Open the project in CLion.
2. Reload CMake if necessary using **Reload CMake Project**.
3. Select the desired exercise in the run target selector.
4. Click **Run** (▶) or **Debug** (🐞).

Each exercise has its own `main()` and can be compiled independently.

---

## 💻 Running from the Terminal

If you prefer to compile manually with `g++`:

### Exercise 1

```bash
g++ -std=c++17 -Wall -Wextra -o exer01 src/Exer01_AjudeSeuMadruga.cpp
./exer01
```

Example:

```bash
echo "5 3
5 3 6 2 3
4 14
2 5 2 5
0 0" | ./exer01
```

Expected output:

```text
4.0000
:D
```

### Exercise 2

```bash
g++ -std=c++17 -Wall -Wextra -o exer02 src/Exer02_TransportePaineisSolares.cpp
./exer02
```

Example:

```bash
echo "4
5 2 1
20 25 30 40 45
9 3 10
20 10 30 40 50 60 90 80 70
10 4 5
65 10 15 14 70 95 65 25 26 35
4 3 1
23 45 77 90" | ./exer02
```

Expected output:

```text
85 $170
150 $4500
151 $3020
235 $235
```

---

## ⚠️ Watch Out For

### Exercise 1 — Ajude Seu Madruga

* The area above the cut must be calculated as `max(Ci - mid, 0)`.
* If the total area is exactly equal to the requested area, no cut is necessary and the output must be `:D`.
* If the total area is smaller than the requested area, the target is impossible and the output must be `-.-`.
* The binary search must use a floating-point precision margin.
* The output must contain exactly **4 decimal places**.

### Exercise 2 — Transporte de Painéis Solares

* The original order of the panels **must be preserved**.
* Each truck receives a contiguous sequence of panels.
* The candidate capacity must be at least the heaviest individual panel.
* The greedy validation determines how many trucks are necessary.
* The objective is to minimize the **maximum load of a truck**.
* The total freight is calculated using the maximum truck load, the number of trucks used, and the freight rate.

---

## 🧠 Concepts Practiced

* Binary Search
* Binary Search on the Answer
* Monotonic functions
* Greedy validation
* Partitioning a sequence into contiguous groups
* Floating-point precision
* Integer arithmetic
* Problem-solving paradigms
* Complexity analysis

---

## ✅ Prerequisites

* C++17-compliant compiler or newer (GCC, Clang, or MSVC)
* CMake ≥ 3.20
* CLion (recommended) or any IDE/editor of your choice

---

## 📚 Reference

Original exercise list:

*Lista de Treinamento — Maratona de Programação*
Instituto Federal de Educação, Ciência e Tecnologia do Triângulo Mineiro — Campus Patrocínio
Date: **24/09/2026**

Sources:

* beecrowd #1912 — **Paradigmas**
* beecrowd #1579 — **Paradigmas**
