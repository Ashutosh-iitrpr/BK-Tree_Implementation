# BK-Tree_Implementation

1. Overview:-
This project implements a BK Tree (Burkhard-Keller Tree), a data structure particularly efficient for approximate string matching. The tree is commonly used in applications like spell checkers and auto-complete systems. It enables searching for words within a certain tolerance of Levenshtein distance, helping find similar words quickly.
2. Project Structure:-
/project-root
├── BK_structure.c            # Defines the core BK Tree structure and main functions.
├── dictionary.c              # Loads a dictionary file into the BK Tree.
├── levenshtein.c             # Implements the basic Levenshtein Distance calculation.
├── Ukkonen_Levenshtein_Distance.c  # Implements Ukkonen's optimized Levenshtein algorithm.
├── header.h                  # Contains function prototypes and macro definitions.
└── dictionary.txt            # Sample dictionary file with a list of words.

3. File Descriptions
3.1 BK_structure.c
Contains the primary BK Tree structure and operations, such as creating nodes, inserting words, depth traversal, and approximate search.

3.2 dictionary.c
Provides functions to load words from a dictionary file into the BK Tree. Uses array_maker to load words into an array and dic_loader to insert these words into the BK Tree.

3.3 levenshtein.c
Implements a basic Levenshtein Distance algorithm to calculate the edit distance between two words.
The lev_dist function is used in approximate search within the BK Tree.

3.4 Ukkonen_Levenshtein_Distance.c
Provides an optimized Levenshtein Distance algorithm based on Ukkonen's algorithm.
UK_lev_dist is used to efficiently calculate edit distance during searches.

3.4 header.h
Contains all necessary function prototypes, constants, and macros used across the project.
Macros like NEG_INF, MAX, and MIN are defined here for convenient usage.

3.6 dictionary.txt
A sample dictionary file with a list of words used to load entries into the BK Tree.
Features
Insertion: Insert words into the BK Tree based on Levenshtein distance.
Search: Find words within a given distance tolerance of a query word.
Autocomplete: Suggest words with a given prefix.
Levenshtein Distance Calculations: Basic and optimized (Ukkonen's) versions of Levenshtein distance.

4. Installation and Compilation
To compile and run the project, use:
bash
Copy the following code
gcc BK_structure.c dictionary.c levenshtein.c Ukkonen_Levenshtein_Distance.c -o bk_tree
./bk_tree

5. Memory Management: The project allocates memory dynamically; ensure there is adequate memory to store large dictionaries.

6. Node Capacity: Currently, each node is restricted to 15 child nodes to maintain simplicity.
