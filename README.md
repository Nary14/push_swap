*This project has been created as part of the 42 curriculum by traomeli, marasolo.*

# push_swap

## Description

`push_swap` is a small sorting project required by the 42 curriculum. The objective is to sort a list of integers using only two stacks (commonly named `a` and `b`) and a limited set of operations (push, swap, rotate, reverse rotate). The challenge is to produce a sequence of operations that sorts the input with the least possible number of moves.

This repository contains an implementation that uses multiple strategies and chooses an appropriate algorithm depending on the input size: a small-size optimized sorter, chunk-based sorting, radix sort for larger inputs, and an adaptive dispatcher that selects the best approach.

Goal: implement a working and efficient `push_swap` program that produces a valid and relatively short operation list for different input sizes while respecting the project's constraints.

## Authors & Contributions

- traomeli — implemented core data structures, `push_swap.h`, most algorithms (algorithms/), and this `README.md`.
- marasolo — implemented parsing and the simple sorting algorithm (parsing/, algorithms/simple_sort.c).

Files of note:
- `push_swap.c` — program entry.
- `push_swap.h` — shared headers and data structures (created by traomeli).
- `parsing/` — input parsing and validation (implemented by marasolo).
- `algorithms/` — sorting strategies: `simple_sort.c`, `chunk_sort.c`, `radix_sort.c`, `adaptive_sort.c`.
- `operations/` — stack operations: `push.c`, `swap.c`, `rotate.c`, `reverse_rotate.c`.
- `utils/` — helper functions and `libft_42` implementation.

## Instructions

### Requirements

- Linux or macOS (Linux tested).
- A C compiler supporting C99 or later (e.g., `gcc`).
- `Make` to build using the provided `Makefile`.

### Compilation

From the repository root run:

sh -c "make"

This will produce the executable `push_swap`.

Available make targets (typical):
- `make` — build `push_swap`.
- `make clean` — remove object files.
- `make fclean` — remove object files and the binary.
- `make re` — rebuild.

### Execution / Usage

Basic usage:

sh -c "./push_swap <list of integers>"

Example:

sh -c "./push_swap 3 2 1"

Output is a list of operations (one per line) that will transform the input stack into a sorted stack in ascending order.

You can use the official `checker` (not included here) or write a simple verifier to apply the operations and ensure the final stack is sorted.

Notes:
- Input validation will detect duplicates and invalid integers and exit with an error message.
- The program expects integers within the signed 32-bit range.

## Usage examples

Example input and an example acceptable output (actual output depends on algorithm and optimizations):

Input: `./push_swap 2 1 3 6 5 8 7 4`
Possible output:

PB
SB
RB
PA
... (operations list)

You can pipe or redirect the output for debugging or feeding it to a checker program.

## Algorithms — explanation and justification

The choice of algorithm is critical to keep the number of operations low for different input sizes. The implementation includes several strategies and an adaptive chooser.

1) Simple sort (small sets)
- Implemented in `algorithms/simple_sort.c` by marasolo.
- Purpose: handle very small inputs (typically 2, 3, 4, 5 elements) with minimal operations.
- Approach: use hand-crafted sequences and pattern detection (for N <= 3 a few hardcoded permutations are enough; for 4-5 a combination of pushing the smallest elements to stack `b` and reinserting in correct order minimizes total moves).
- Complexity and justification: For tiny N, overhead of general algorithms is unnecessary; targeted sequences achieve optimal or near-optimal operation counts.

2) Chunk sort
- Implemented in `algorithms/chunk_sort.c` (traomeli).
- Purpose: efficient for medium-sized inputs (e.g., 100 elements typical for 42 projects).
- Approach: divide the sorted index range into several chunks. Push elements from `a` to `b` chunk by chunk using rotations to minimize moves, then push back from `b` to `a` selecting the best candidate each time (usually the largest in `b`).
- Complexity and justification: chunking reduces the number of rotations and spreads work across smaller regions. With tuned chunk sizes (empirically chosen), this approach gives good results for mid-sized inputs and is commonly accepted in 42 solutions.

3) Radix sort (binary)
- Implemented in `algorithms/radix_sort.c` (traomeli).
- Purpose: handle large sets where deterministic O(n log n) or O(n * k) behavior is preferable.
- Approach: use a binary LSD radix on indices rather than values (map values to their rank/index first). For each bit position, iterate through stack `a` and push elements with 0 in that bit to stack `b`, then push them back. Repeat for each bit position up to the maximum needed to represent the ranks.
- Complexity and justification: Radix sort on ranks runs in O(n * k) where k is number of bits (~log2(n)). For large n, this is very efficient and simple to implement with allowed stack operations. It is also stable regarding operation count growth and predictable.

4) Adaptive strategy
- Implemented in `algorithms/adaptive_sort.c` (traomeli).
- Purpose: choose the best algorithm depending on number of elements.
- Heuristics used:
  - N <= 3: simple_sort (hardcoded minimal moves)
  - N <= 5: simple_sort with push/back optimizations
  - N <= ~150: chunk_sort with tuned chunk sizes
  - N > ~150: radix_sort for predictable performance
- Justification: No single strategy is universally optimal. The adaptive approach leverages the fast, optimal small-N routines and switches to chunk-based or radix-based strategies which scale better for larger inputs. These heuristics are derived from common 42 solutions and empirical testing.

Design notes and trade-offs
- Using ranks (indexing values from 0..n-1) simplifies algorithms like radix and chunk because they operate on the relative order rather than absolute values.
- Chunk sorting requires tuning chunk size; the implementation chooses chunk counts based on N to balance the number of pushes/rotates.
- Radix is simple and stable but may produce more operations than a perfectly tuned chunk approach for medium N. The adaptive selection mitigates this.

## Complexity classes used in this project — definitions, utility, and rationale

This project groups algorithms into three complexity classes and a custom adaptive strategy. Below are precise definitions, what they mean for push_swap, why each class is useful, and why an intermediate "medium" class can be preferable to a naive quadratic approach.

Big-O primer
- Big-O describes an asymptotic upper bound on how an algorithm's time or operations grow as the input size n increases. In push_swap the primary cost model is the number of stack operations (push, swap, rotate, reverse-rotate) and the additional CPU work to decide which operations to emit.

1) Quadratic class — O(n^2)
- Definition: the work (or number of operations) grows on the order of n squared. Typical patterns involve nested passes over the data (for each element, potentially scanning the remaining elements).
- Examples in this repository: insertion-/selection-/bubble-style adaptations and direct min/max extraction methods. These are implemented as the "simple sort" routines.
- Utility in push_swap: For very small n (2..5) or very low disorder, O(n^2) methods are simple to implement and can be optimal in the number of emitted stack operations because they rely on hand-optimized sequences and local fixes. The constant factors are small and the absolute number of operations remains low when n is small.
- Upper bound argument (operations/space): in the push_swap model a naive quadratic routine may perform up to c * n^2 stack operations (c a small constant). Space overhead is O(1) extra (a few indices and counters) beyond the two stacks.

2) Medium class — O(n * m) where m = number of chunks (notation often written by authors as O(n·n_chunks) or O(n n))
- Definition: medium algorithms partition the problem into m chunks or blocks, then perform a pass (or limited passes) per chunk. The total work is proportional to n times the number of chunks m.
- Examples: chunk-based sorting, block partitioning, bucket-style adaptations with a fixed or sub-linear number of buckets.
- Why this differs from plain O(n^2): if m is chosen significantly smaller than n (for example m = sqrt(n) or m = log n or a tuned constant), the total complexity O(n * m) becomes asymptotically better than O(n^2). For instance, if m = sqrt(n), complexity is O(n * sqrt(n)) which grows much slower than O(n^2) as n increases.
- Utility in push_swap: chunk strategies reduce the number of rotations and local scans by focusing on a limited range of ranks at a time. Proper tuning of m (chunk count) gives good practical trade-offs between number of pushes and rotations and tends to produce fewer operations than blind quadratic routines for medium-sized inputs (e.g., ~100 elements).
- Upper bound argument (operations/space): each chunk typically requires scanning/rotating the stack to locate its elements and a bounded number of pushes. If finding each element takes at most O(n) and there are m chunks, a conservative upper bound is O(n * m) stack operations. Additional working space is O(m) or O(1) depending on how chunk boundaries are computed (we usually precompute ranks so extra space is O(n) for that mapping).

3) Complex class — O(n log n)
- Definition: algorithms whose work grows as n times a logarithmic factor. In the push_swap model this often corresponds to approaches that exploit bit decomposition or divide-and-conquer patterns mapped to limited stack operations.
- Example: binary radix on ranks (LSD) implemented here behaves like O(n * k) where k is number of bits for indices; since k ≈ log2(n), complexity is O(n log n). Merge/quick-like adaptations or heap-like strategies can also target this class.
- Utility in push_swap: O(n log n) algorithms scale much better for large n and high disorder — they provide predictable and reasonable operation counts. Radix on ranks is simple and fits well with stack operations, giving consistent performance when the number of elements is large.
- Upper bound argument (operations/space): radix performs k passes (k ≈ log2 n) over n elements, each pass performing a bounded number of stack operations per element (push or rotate), so O(n log n) operations in total. Space overhead is O(n) for the rank mapping.

Why a medium O(n * m) algorithm can be better than O(n^2)
- The key is how m scales with n. O(n^2) assumes m ≈ n (one effective inner pass per element), whereas an O(n * m) algorithm purposefully keeps m much smaller than n via chunking or bucketing.
- In practice, chunk_sort chooses m such that the number of full-stack scans and expensive rotations is reduced, producing far fewer total stack operations for typical 42 test sizes (e.g., 100 elements). Thus, though both are conceptually "nested" strategies, tuning m yields tangible improvements.

Adaptive strategy, disorder thresholds, and complexity guarantees
- Disorder metric: we measure disorder as a normalized quantity between 0 and 1. A simple and practical metric is the number of inversions divided by the maximum possible inversions (n * (n - 1) / 2). This gives a real in [0,1], where 0 means already sorted and 1 means reversed.

- Thresholds used (documented and implemented in `algorithms/adaptive_sort.c`):
  - Low disorder: disorder < 0.2 -> use O(n^2) simple routines. Rationale: when the permutation is almost sorted, a small number of local swaps and pushes fix the sequence with few operations; quadratic routines with small constants achieve minimal emitted moves.
  - Medium disorder: 0.2 ≤ disorder < 0.5 -> use medium chunk-based sorting (O(n * m)). Rationale: when there is moderate disorder, chunking reduces global scanning and limits the number of rotations per element. Choosing m proportional to a tuned function of n (for example m ≈ sqrt(n) or empirically tuned constants for the 42 test sizes) achieves substantially fewer operations than naive quadratic approaches.
  - High disorder: disorder ≥ 0.5 -> use complex/radix approach (O(n log n)). Rationale: when disorder is high, local fixes are inefficient; a global logarithmic-factor algorithm like radix on ranks provides the best asymptotic behavior and stable operation counts.

- Complexity claims in the push_swap model:
  - Low disorder regime: O(n^2) worst-case but with small constants and very small absolute operation counts for low-disorder inputs. Space O(1).
  - Medium disorder regime: O(n * m) where m is chosen so that m << n; with m = O(sqrt(n)) this becomes O(n * sqrt(n)) — asymptotically better than O(n^2). Space O(n) for rank mapping, O(1) extra for chunk pointers.
  - High disorder regime: O(n log n) operations and O(n) extra space for ranks.

Notes on practical tuning
- The exact numeric thresholds (0.2 and 0.5) and chunk sizing functions are empirical choices intended to balance typical 42 test cases (small, medium, large). They are documented here so reviewers can reproduce and adjust them. If you change the chunk count function, update the README with the new expected complexity behaviour.

## File structure

- `Makefile` — build rules.
- `push_swap.c` — main entry.
- `push_swap.h` — headers and shared structs.
- `algorithms/` — sorting algorithms and dispatcher.
- `operations/` — stack primitive operations.
- `parsing/` — input parsing and error handling.
- `utils/` — utility helpers and `libft_42`.

## Testing and validation

- Use `make` to compile.
- Manually run `./push_swap` with sample inputs.
- Optionally use the `checker` program (if available) to validate the operation sequence produced by `push_swap` results in a sorted stack.
- Use `valgrind` or similar to check for leaks:

sh -c "valgrind --leak-check=full ./push_swap 5 2 3 1 4"

## Resources

Classic references and helpful materials:
- 42 subject and intranet documentation (project-specific rules and constraints).
- "Push_swap" community write-ups and tutorials (search "push_swap 42 tutorial", "push_swap chunk sort", "push_swap radix sort").
- Articles on radix sort, bucket/chunk strategies, and stack-based sorting.
- C programming references and data-structure materials.

AI usage

- AI assistance: The README and algorithm explanations were drafted and edited with the help of an AI writing assistant. The assistant helped to shape the README text, clarify algorithm descriptions, and suggest structuring and phrasing improvements.
- Code authorship: All source code in this repository (`push_swap.h`, parsing, algorithms, operations, etc.) was written and implemented by the project authors listed above. AI was not used to generate production source code in this repository — its role was limited to documentation and explanatory text.

If AI was used to produce any code snippets during development, those snippets were reviewed and adapted by the authors before inclusion.

## Notes and future improvements

- Possible improvements: more aggressive operation count minimization, finer chunk-size tuning, or additional heuristics for choosing rotation directions.
- Adding a `checker` and more automated test harnesses will make it easier to validate and compare strategies.

## Contact

Authors:
- traomeli — main algorithms, headers, repo structure
- marasolo — parsing and small-size algorithm

License: none specified — please contact the authors for reuse permission.

---

For questions about implementation details, algorithm choices, or contribution, open an issue or contact the authors directly.