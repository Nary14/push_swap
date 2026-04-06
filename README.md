*This project has been created as part of the 42 curriculum by traomeli, marasolo.*

# push_swap

## Description

`push_swap` is a sorting project from the 42 curriculum. The goal is to sort a list of integers using only two stacks (named `a` and `b`) and a limited set of operations (push, swap, rotate, reverse rotate), using the fewest operations possible.

This repository implements multiple sorting strategies and an adaptive dispatcher that selects the best algorithm depending on input size and disorder level.

## Authors & Contributions

- **traomeli** — all stack operations (swap, push, rotate, reverse_rotate), stack_utils (new_node, add_front, add_back, stack_size, is_sorted, free_stack), assign_index, radix_sort, chunk_sort, adaptive_sort, push_swap.c, push_swap.h, disorder.c, Makefile, README.md. Refactored all files to use the t_node structure.
- **marasolo** — initial parsing structure (parsing/error.c, parsing/parse.c), initial simple_sort skeleton (algorithms/simple_sort.c).

## File structure

```
push_swap/
├── Makefile
├── push_swap.c              # main entry point
├── push_swap.h              # shared headers and structs
├── push_swap_utils.c        # helpers used by main and runs
├── stack_utils.c            # node creation, add_front/back, size, sorted, free
├── stack.c                  # t_node implementation
├── parse.c                  # argument parsing and validation
├── error.c                  # error handling, duplicate and validity checks
├── disorder.c               # assign_index, ft_atol, disorder metric
├── bench.c                  # bench counters and logging
├── bench_print.c            # bench printing helpers
├── ft_adaptive_sort.c       # dispatcher — picks the right algorithm
├── ft_simple_sort.c         # simple sort (2..5 elements)
├── ft_chunk_sort.c          # chunk-based algorithm
├── ft_chunk_utils.c         # helpers for chunk sort
├── ft_radix_sort.c          # radix sort algorithm
├── rotate_to_top_a_b.c      # helpers to rotate elements to top
├── rotate.c                 # rotate operations (ra, rb, rr)
├── reverse_rotate.c         # reverse rotate ops (rra, rrb, rrr)
├── push.c                   # push operations (pa, pb)
├── swap.c                   # swap operations (sa, sb, ss)
├── ft_float.c               # print float
└── libft_42/                # subset of libft used by the project (many ft_*.c)
```

## Instructions

### Requirements

- Linux or macOS
- C compiler (cc) supporting C99 or later
- Make

### Compilation

```bash
make
```

Available targets:
- `make` — build `push_swap`
- `make clean` — remove object files
- `make fclean` — remove object files and binary
- `make re` — full rebuild

### Execution

```bash
./push_swap <list of integers>
```

Example:
```bash
./push_swap 5 3 1 4 2
```

Output is a list of operations (one per line) that sorts the input stack in ascending order.

### Validation with checker

```bash
chmod +x checker_linux
ARG="5 3 1 4 2" && ./push_swap $ARG | ./checker_linux $ARG
```

Should print `OK` if the operations correctly sort the stack.

### Error handling

```bash
./push_swap 1 2 one    # Error — not an integer
./push_swap 1 2 2      # Error — duplicate
./push_swap            # no output, no error
```

## Usage examples

```bash
# Already sorted — no output
./push_swap 1 2 3

# 3 elements
./push_swap 3 2 1
# Output: sa rra

# 5 elements
./push_swap 5 3 1 4 2

# 100 random numbers
shuf -i 0-999 -n 100 > args.txt
./push_swap $(cat args.txt) | wc -l

# 500 random numbers
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

## Algorithms — explanation and justification

### Data structure

We use a custom singly-linked list `t_node` with three fields:
- `value` — the actual integer
- `index` — its rank in the sorted order (0 = smallest)
- `next` — pointer to next node

Using `index` instead of `value` in algorithms like radix_sort simplifies the logic and makes it work with any integer range.

### 1. Simple sort — O(n²)

**File:** `simple_sort.c` — initial skeleton by marasolo, completed by traomeli.

**For 2 elements:** one `sa` if needed.

**For 3 elements:** five hardcoded cases covering all permutations with at most 2 operations.

**For 4-5 elements:** push the minimum to B repeatedly until 3 remain, sort those 3, then push B back.

**Justification:** for tiny inputs, pattern-based approaches produce fewer operations than general algorithms. Overhead of chunk or radix is unnecessary.

### 2. Chunk sort — O(n√n)

**File:** `chunk_sort.c` — implemented by traomeli.

**Approach:**
1. Build a sorted reference array of values using `qsort`
2. Divide it into `chunks` groups (chunk count = size / 10, min 1)
3. For each chunk, find elements in A that belong to that value range and push them to B (rotating A to bring them to the top). Elements below the chunk median get rotated in B.
4. After all chunks are processed, pop from B by always bringing the maximum to the top first.

**Justification:** chunking reduces the number of full-stack scans. Instead of scanning for the global min every time (O(n²)), we scan for elements within a bounded range, spreading the work efficiently. With tuned chunk sizes this gives good results for ~100 elements.

### 3. Radix sort — O(n log n)

**File:** `radix_sort.c` — implemented by traomeli.

**Approach:** LSD binary radix on `index` values (ranks 0..n-1):
- For each bit position from LSB to MSB:
  - Scan all n elements of A
  - If bit = 0 → push to B
  - If bit = 1 → rotate A
  - Push everything from B back to A
- Repeat for all bits needed to represent the maximum index

**Justification:** radix on ranks performs exactly `n * k` operations where k = number of bits ≈ log2(n). For 500 elements this is ~9 passes × 500 = ~4500 operations, which is well within the excellent performance target (<5500).

### 4. Adaptive strategy

**File:** `adaptive_sort.c` — implemented by traomeli.

The dispatcher selects the algorithm based on input size:

| Size | Algorithm | Complexity |
|------|-----------|------------|
| Already sorted | return immediately | O(n) |
| ≤ 5 | simple_sort | O(n²) |
| ≤ 100 | chunk_sort | O(n√n) |
| > 100 | radix_sort | O(n log n) |

**Disorder metric:** disorder is measured as inversions / max_inversions, giving a value in [0, 1]. This metric is computed before sorting and could be used to refine the threshold decisions.

**Justification:** no single algorithm is optimal for all sizes. The adaptive approach combines:
- Fast hardcoded sequences for tiny inputs
- Chunk-based locality for medium inputs
- Predictable bit-manipulation for large inputs

## Complexity classes summary

| Class | Growth | Used for |
|-------|--------|----------|
| O(n²) | Quadratic | n ≤ 5 |
| O(n√n) | Sub-quadratic | n ≤ 100 |
| O(n log n) | Linearithmic | n > 100 |

Why O(n√n) beats O(n²): if chunk count m = √n, total work is O(n × √n) which grows much slower than O(n²) as n increases. For n=100: n²=10000 vs n√n≈1000.

## Performance targets

| Input size | Pass | Good | Excellent |
|------------|------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

## Resources

- 42 project subject (push_swap rules and constraints)
- Community write-ups: search "push_swap 42 chunk sort", "push_swap radix sort"
- Wikipedia: Radix sort, Insertion sort, Big-O notation
- C standard library: `qsort`, `malloc`, `write`

## AI usage

Claude (Anthropic) was used throughout this project as a **learning and guidance tool**. It explained concepts step by step — linked lists, pointer manipulation, stack operations, algorithm design — and guided the implementation without writing code directly. All code was written, understood, and can be defended by the authors.

Claude also helped structure and refine this README.

## Add `--count-only` option

## Goal

Add a `--count-only` option to `push_swap` to print **only the total number of operations** required to sort the input, without printing the operations one by one.

```bash
# Expected behavior
./push_swap --count-only 3 2 1       # prints: 2
./push_swap --count-only 10 9 8 7 6 5 4 3 2 1  # prints: 29
./push_swap 3 2 1                    # unchanged behavior: sa / rra
```

---

## Understand the architecture before coding

Before touching any code, explain to the evaluator why this change is simple:

The project already has a `t_bench` struct (in `push_swap.h`) that **counts every operation** (sa, pb, ra, etc.), and a function `bench_log()` (in `bench.c`) that is called on each operation to both print and count it.

So we do **not** need to create a new counter — we only need to:
1. Add a `count_only` field to `t_bench`
2. Modify `bench_log()` so it does not print when `count_only` is active
3. Detect the `--count-only` flag in `parse_flags()`
4. Print the total at the end of `main()`

**3 files changed, ~15 lines added.**

---

## Step 1 — `push_swap.h`: add the field and declare the function

Open `push_swap.h`. Find the `t_bench` struct and add `int count_only` right after `int active`:

```c
// BEFORE
typedef struct s_bench
{
    int     active;
    char    *strategy_name;
    ...
} t_bench;

// AFTER
typedef struct s_bench
{
    int     active;
    int     count_only;      // <- added line
    char    *strategy_name;
    ...
} t_bench;
```

Then, in the function declarations section add `bench_total()` alongside the other bench functions:

```c
// BEFORE
void    bench_log_ops(char *op);
void    bench_print_summary(double disorder);

// AFTER
void    bench_log_ops(char *op);
void    bench_print_summary(double disorder);
long    bench_total(void);       // <- added declaration
```

---

## Step 2 — `bench.c`: change `bench_log()` and add `bench_total()`

### 2a — Modify `bench_log()`

```c
// BEFORE
void    bench_log(char *op, int print)
{
    if (print)
        ft_putstr_fd(op, 1);
    if (!ft_bench()->active)
        return ;
    ...
}

// AFTER
void    bench_log(char *op, int print)
{
    if (print && !ft_bench()->count_only)   // <- do not print when count_only
        ft_putstr_fd(op, 1);
    if (!ft_bench()->active && !ft_bench()->count_only)  // <- still count when count_only
        return ;
    ...
}
```

Explanation: the first line prevents printing each operation when `count_only` is active. The second line forces counting even if `--bench` was not passed.

### 2b — Add `bench_total()` at the end of the file

```c
long    bench_total(void)
{
    t_bench *b;

    b = ft_bench();
    return (b->sa + b->sb + b->ss + b->pa + b->pb
        + b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr);
}
```

---

## Step 3 — `push_swap.c`: detect the flag and print the result

### 3a — Detect `--count-only` in `parse_flags()`

```c
// BEFORE
while (i < argc)
{
    if (is_flag(argv[i], "--bench", 7))
        *bench = 1;
    else if (is_flag(argv[i], "--simple", 8) && ++sc)
    ...
}

// AFTER
while (i < argc)
{
    if (is_flag(argv[i], "--bench", 7))
        *bench = 1;
    else if (is_flag(argv[i], "--count-only", 12))  // <- added block
        ft_bench()->count_only = 1;
    else if (is_flag(argv[i], "--simple", 8) && ++sc)
    ...
}
```

### 3b — Print the total at the end of `main()`

```c
// BEFORE
    ft_run_if_unsorted(&a, &b, params);
    free_stack(&a);

// AFTER
    ft_run_if_unsorted(&a, &b, params);
    if (ft_bench()->count_only)                          // <- 2 lines added
        ft_putnbr_fd(bench_total(), 1), ft_putstr_fd("\n", 1);
    free_stack(&a);
```

---

## Step 4 — Build and demo

```bash
make re
```

### Demo for the evaluator

```bash
# 3-element reversed
./push_swap --count-only 3 2 1
# → 2

# 10-element reversed
./push_swap --count-only 10 9 8 7 6 5 4 3 2 1
# → 29

# Normal mode unchanged
./push_swap 3 2 1
# → sa
# → rra

# Already sorted — should print 0
./push_swap --count-only 1 2 3
# → 0

# Consistency check: the count-only result should match the number of printed lines
./push_swap 5 1 4 2 3 | wc -l
./push_swap --count-only 5 1 4 2 3
# → both should produce the same number
```

---

## Summary of changes

| File | Change |
|---|---|
| `push_swap.h` | +`count_only` field in `t_bench`, +`bench_total()` declaration |
| `bench.c` | Modify `bench_log()` (small change), add `bench_total()` |
| `push_swap.c` | Add `--count-only` detection in `parse_flags()`, print total in `main()` |

