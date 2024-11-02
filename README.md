# BK-Tree_Implementation

## 1. Overview

This project implements a dual-function BK Tree (Burkhard-Keller Tree) system. The BK Tree, a data structure designed for efficient approximate matching, has been adapted here for two purposes: managing geographic data on hospitals and performing approximate string matching for words. In the hospital application, the BK Tree finds nearby hospitals based on geographic coordinates, using haversine distance to calculate proximity. For words, it facilitates approximate matching, common in applications like spell checkers and auto-complete, by finding words within a specified Levenshtein distance.

## 2. Project Structure

```bash
/BK-Tree_Implementation
├── Hosp_BK_structure.c                 # Defines BK Tree structure and functions for hospital proximity search.
├── BK_structure.c                      # Defines BK Tree structure and functions for approximate word matching.
├── dictionary.c                        # Loads a dictionary file into the BK Tree for word matching.
├── levenshtein.c                       # Implements the basic Levenshtein Distance calculation.
├── Ukkonen_Levenshtein_Distance.c      # Implements Ukkonen's optimized Levenshtein algorithm.
├── header.h                            # Contains function prototypes, macros, and struct definitions.
├── dictionary.txt                      # Sample dictionary file for words.
├── hospital_data.csv                   # Sample CSV file with hospital names, latitudes, and longitudes.
└── README.md                           # Documentation file with project details, structure, and usage.

## 3. File Descriptions

- **Hosp_BK_structure.c:** Contains the BK Tree structure and functions for managing hospital data. Key functions include:
  - `createNode`: Creates a node for each hospital with its name, latitude, and longitude.
  - `haversine_distance`: Calculates geographic distance between nodes.
  - `insertNode`: Inserts hospitals based on geographic distances.
  - `depth_traverse`: Traverses the BK Tree to display hospital names.
  - `searchBKTree`: Finds hospitals within a given distance range from specified coordinates.
  - `read_csv`: Loads hospital data from `hospital_data.csv` into the BK Tree.

- **BK_structure.c:** Contains the core BK Tree structure and operations for managing words, including:
  - `createNode`: Initializes nodes representing each word in the BK Tree.
  - `insertNode`: Inserts words based on Levenshtein distance, grouping words by similarity.
  - `depth_traverse`: Traverses the BK Tree to display words, helpful for testing and visualization.
  - `approximateSearch`: Finds words within a given Levenshtein distance of a query, supporting approximate string matching.
  - `autocomplete`: Suggests words based on a prefix, enhancing user experience in applications like auto-complete.

- **dictionary.c:** Loads words from `dictionary.txt` into the BK Tree for word-based approximate matching. It includes helper functions to load words into an array and insert them into the BK Tree.

- **levenshtein.c:** Implements the basic Levenshtein Distance algorithm, calculating the edit distance between words for approximate matching.

- **Ukkonen_Levenshtein_Distance.c:** Provides an optimized Levenshtein Distance calculation using Ukkonen's algorithm, offering faster searches in large dictionaries.

- **header.h:** A centralized header that includes macros, constants, and function prototypes for the entire project. Key elements include:
  - Macros for useful constants, such as `M_PI` and utility functions like `MAX` and `MIN`.
  - `NODE_CAPACITY` for restricting each node to a set number of children.
  - Struct definitions for nodes in both hospital and word trees, containing fields for longitude, latitude, and name (in hospital BK Tree) or word (in the word BK Tree).
  - Function prototypes for hospital and word operations, such as `createNode`, `insertNode`, `haversine_distance`, `lev_dist`, and `UK_lev_dist`, as well as memory management functions to ensure proper resource usage.

- **dictionary.txt:** A sample file with words to populate the word BK Tree, supporting approximate matching tests.

- **hospital_data.csv:** A sample CSV file containing hospital data with names, latitudes, and longitudes, used to build the hospital BK Tree for proximity searches.

- **README.md:** This documentation file provides an overview of the project, including its structure, features, installation instructions, and usage details.

## 4. Features

### Hospital Search:
- **Insertion:** Adds hospitals to the BK Tree based on geographic (haversine) distance.
- **Proximity Search:** Finds hospitals within a specified distance range from a location.
- **Traversal:** Traverses the tree to display hospital names.

### Word Matching:
- **Insertion:** Adds words to the BK Tree based on Levenshtein distance.
- **Approximate Search:** Finds words within a specified Levenshtein distance.
- **Autocomplete:** Suggests words based on a given prefix.
- **Levenshtein Distance Calculations:** Includes both basic and optimized (Ukkonen's) versions.

## 5. Installation and Compilation

To compile and run the project, use the following commands:

```bash
gcc Hosp_BK_structure.c -o hosp_bk_tree
./hosp_bk_tree

gcc BK_structure.c dictionary.c levenshtein.c Ukkonen_Levenshtein_Distance.c -o word_bk_tree
./word_bk_tree

## 6. Memory Management

Both the hospital and word BK Trees use dynamic memory allocation for nodes and child pointers. This approach allows for efficient storage and retrieval in larger datasets. However, ensure that adequate memory is available, especially when working with large files. A memory cleanup function (`free_tree`) is provided to release all allocated memory after execution, which helps prevent memory leaks and keeps the application resource-efficient.

## 7. Node Capacity

Each BK Tree node has a fixed number of child nodes for simplicity. In the word BK Tree, `NODE_CAPACITY` is set to 15, which keeps the tree levels manageable and aids efficient searches. For the hospital BK Tree, each node can hold up to 23 children, leveraging geographic distance partitioning to optimize search and insertion operations. These limits help maintain a balanced and traversable tree structure in both applications.
