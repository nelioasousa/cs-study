# The Algorithm Design Manual, 3rd edition
Book by Steven S. Skiena.

## Chapter 1: Introduction to Algorithm Design
> To be interesting, an algorithm must solve a general, well-specified problem.

That is, an algorithm that solves just an instance of a problem isn't cool. An algorithm that sorts an array of any size is better than one that sorts just 10-element arrays. The "10-element arrays" is, in fact, a subset of a general sorting problem. An instance of a sorting problem would be a defined array like `int arr[5] = {4, 1, 2, 0, 3}`.

> This distinction, between a problem and an instance [or subset] of a problem, is fundamental.

The desired properties for a good algorithm:
1. Correct;
2. Efficient;
3. Easy to implement.

> These goals may not be simultaneously achievable.

### 1.1 Robot Tour Optimization
The book started with a nice pratical example: the *traveling salesman problem* (TSP). My first thought about it was the nearest point *heuristic*, but in the back of my mind I knew something was off with it.

>  There is a fundamental difference between algorithms, procedures that always produce a correct result, and heuristics, which may usually do a good job but provide no guarantee of correctness.

### 1.2 Selecting the Right Jobs
> Ensuring the optimal answer over all possible inputs is a difficult but often achievable goal. Seeking counterexamples that break pretender algorithms is an important part of the algorithm design process.

> Reasonable-looking algorithms can easily be incorrect. Algorithm correctness is a property that must be carefully demonstrated.

### 1.3 Reasoning about Correctness
> Correct algorithms require careful exposition, and efforts to show both correctness and not incorrectness.

> The heart of any algorithm is an idea. If your idea is not clearly revealed when you express an algorithm, then you are using too low-level a notation [english/text, pseudocode, programming language, mathematical notation, others] to describe it.

> No rational person will ever defend the correctness of an algorithm after a counter-example has been identified. Very simple instances can instantly defeat reasonable-looking heuristics with a quick *touché*.

> Once a counterexample has been found, it is worth simplifying it down to its essence.

### 1.4 Induction and Recursion
Just a dirty gloss over... I need to search more to get a stronger grip of induction. Better study something [written by a mathematician](https://www.sydney.edu.au/content/dam/students/documents/mathematics-learning-centre/mathematical-induction.pdf).

### 1.5 Modeling the Problem
> Modeling is the art of formulating your application in terms of precisely described, well-understood problems. Proper modeling is the key to applying algorithmic design techniques to real-world problems.

> To exploit the algorithms literature, you must learn to describe your problem abstractly, in terms of procedures on such fundamental structures.

Those "fundamental structures" can be:
- Permutations
- Subsets
- Trees
- Graphs
- Points (or vectors/matrices)
- Polygons/Polyhedrons
- Strings

> Temporarily ignoring details that don’t fit [a particular structure] can free the mind to ask whether they really were fundamental in the first place.

> Recursive descriptions of objects require both decomposition rules and basis cases, namely the specification of the smallest and simplest objects where the decomposition stops. [...] The decision of whether the basis case contains zero or one element [or more than one] is more a question of taste and convenience than any fundamental principle.

### 1.8 War Story: Psychic Modeling
Permutation is as interesting as it is challenging: a damn lot.

> *We hadn't modeled the problem correctly!*

## Chapter 2: Algorithm Analysis
Big-Oh: `f(x) = O(g(x))` if there is a positive constant `c` where `c * g(x) >= f(x)` for `x` greater than some initial value `n`.

Omega: `f(x) = Omega(g(x))` if there is a positive constant `c` where `c * g(x) <= f(x)` for `x` greater than some initial value `n`.

Theta: `f(x) = Theta(g(x))` if `f(x) = O(g(x))` and `f(x) = Omega(g(x))` for `x` greater than some initial value `n`.

## Chapter 3: Data Structures
There are contiguous data structures and linked data structures, sometimes both (likes Tries). Some advantages of linked structures over arrays:
- There's no "running out of bounds", since a arbitrary located memory space can be linked to the structure;
- Insertion and deletion are more simple, since there's no need to keep the structure contiguous;
- With large records (large objects being store in memory), moving pointers is easier than moving the objects itself.

Now, the advatages of arrays (continguous structures) over linked structures:
- Space efficiency, since there's no need to reserve memory for pointers (linked strucures have more metadata);
- Random access, allowing constant time lookups given the item index;
- Better memory locality and cache performance than random pointer jumping.

A dictionary is an abstract data type for storing mappings of elements (key-value pairs). To store an object `x` in a dictionary, we must supply a key that uniquely identifies this object. The key can be embedded in the object (e.g., as an attribute `x.key`) or can be externally supplied. The object can then be queried using only the key. The operatios supported by a dictionary can be summarized as:
- `Search(D, k)`: `D` is the dictionary instance and `k` is the key;
- `Insert(D, x)`: `x` is the object to be stored in the dictionary using `x.key` as the key;
- `Delete(D, x)`: `x` is the object to be deleted (if present) from the dicitonary `D`;

Some dictionary implementations remember the order of insertion, while others store the keys in sorted order. It is also common to not guarantee any specific order of iteration over the dictionary elements, especially in hash table implementations.

The book pointed out the efficiency of basic operations in dictionary implementations using sorted and unsorted arrays, singly linked lists, and doubly linked lists.

The book have a really good introduction to binary search trees and about they insertion/search/deletion operations and efficiency. Also, briefly explain balanced binary trees.
