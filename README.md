# 1. Disaster Response Resource coordination System

A menu-driven **C++ console application** for managing disaster-relief
resources such as water bottles, food packets, medicines, and first-aid
kits. It allows users to add resources, view stock, register relief
requests, dispatch resources, undo the last dispatch, and view activity
history.

## Table of Contents
## Project Resources

- [Algorithm](https://github.com/VishalThorat07/DSA-PROJECT-CCE/blob/main/linked%20list/algorithm/Algorithm_Disaster_Management.pdf)

- [Flowchart PDF](https://github.com/VishalThorat07/DSA-PROJECT-CCE/blob/main/linked%20list/Flowchart/Flowchart_Disaster_Management.pdf)

- [Output PDF](https://github.com/VishalThorat07/DSA-PROJECT-CCE/blob/main/linked%20list/code%201/disaster%20response%20resource%20coordination%20sysytem.cpp)

- [Source Code](https://github.com/VishalThorat07/DSA-PROJECT-CCE/blob/main/linked%20list/output/disaster%20response%20output.pdf)
- [Detail Flowchart](#flowchart)
## Objective

To help organize disaster-relief supplies and requests through a simple
computer-based system. The program maintains available quantities and
records successful dispatches so that resources can be tracked during an
emergency.

## Features

1.  **Add Resource** --- add a new resource or increase the quantity of
    an existing one.
2.  **Display Resources** --- display all resources and their available
    quantities.
3.  **Register Request** --- register a request for a resource.
4.  **Display Requests** --- view all registered requests and their
    statuses.
5.  **Dispatch** --- fulfil a pending request when sufficient stock is
    available.
6.  **Undo Last Dispatch** --- reverse the most recent successful
    dispatch.
7.  **Display History** --- display resource-management activities.
8.  **Exit** --- close the application.


## Algorithm

1.  Start the program.
2.  Create empty lists for resources, requests, and history.
3.  Display the main menu.
4.  Read the user's choice.
5.  If the choice is **1**, ask for a resource name and quantity; add it
    or update its stock.
6.  If the choice is **2**, display all available resources.
7.  If the choice is **3**, ask for a resource name and required
    quantity; register a pending request.
8.  If the choice is **4**, display all requests and their statuses.
9.  If the choice is **5**, select a pending request, check the
    available stock, and dispatch the requested quantity if stock is
    sufficient.
10. If the choice is **6**, restore the stock and pending status of the
    most recent successful dispatch.
11. If the choice is **7**, display the activity history.
12. If the choice is **8**, terminate the program.
13. For an invalid choice, display an error message.
14. Repeat from Step 3 until the user chooses Exit.
15. Stop.

## Flowchart

The following Mermaid flowchart is rendered by many Markdown viewers,
including GitHub.

``` mermaid
flowchart TD
    A([Start]) --> B[Initialize resources, requests and history]
    B --> C[Display main menu]
    C --> D[/Enter choice/]
    D --> E{Choice}
    E -->|1 Add Resource| F[Read name and quantity; add or update stock]
    E -->|2 Display Resources| G[Display available resources]
    E -->|3 Register Request| H[Read resource and quantity; save pending request]
    E -->|4 Display Requests| I[Display all requests]
    E -->|5 Dispatch| J[Select a pending request]
    J --> K{Enough stock available?}
    K -->|Yes| L[Reduce stock and mark request dispatched]
    K -->|No| M[Show insufficient stock or invalid request]
    L --> N[Save dispatch record and history]
    F --> O{Exit selected?}
    G --> O
    H --> O
    I --> O
    M --> O
    N --> O
    E -->|6 Undo Dispatch| P[Restore last dispatch if possible]
    E -->|7 Display History| Q[Display activity history]
    E -->|8 Exit| R([Stop])
    P --> O
    Q --> O
    O -->|No| C
    O -->|Yes| R
    E -->|Invalid choice| S[Show invalid choice]
    S --> C
```
# 2. Book ID Lookup System using Threaded Binary Search Tree

A menu-driven library catalogue tool that stores book IDs in a **threaded binary search tree**. NULL pointers are replaced with threads, so the catalogue can be traversed in sorted order and the next book can be found without recursion, an explicit stack, or wasted pointers.

## Why Threaded BST?

| Problem with a plain BST | How this project solves it |
|---|---|
| Inorder traversal needs recursion or a stack | Threads link each node directly to its inorder successor |
| Finding the next book in order is slow | Successor lookup follows one thread or a short leftmost walk |
| Many pointers are NULL and unused | Every NULL pointer is reused as a thread |

## Features

- **Insert** a unique Book ID in BST order, with automatic thread updates
- **Find the inorder successor** of any book, using threads only
- **Inorder traversal** of all Book IDs in sorted order, without recursion or a stack
- **Thread display** showing every node's left and right link as a child or a thread
- Duplicate ID rejection, missing-ID and last-book messages, and input validation

## How Threads Work

- A NULL **left** pointer points to the node's **inorder predecessor**.
- A NULL **right** pointer points to the node's **inorder successor**.
- Each node stores flags (`leftThread`, `rightThread`) to tell a thread from a child link.
- The leftmost node's left thread and the rightmost node's right thread remain NULL.

## Example

Insert the IDs `50, 30, 70, 20, 40, 60`:

```
Inorder traversal : 20  30  40  50  60  70
Successor of 30   : 40
Successor of 70   : No inorder successor (last book).
Successor of 99   : Book ID not found.
```

## Project Structure

```
.
├── src/
│   └── ThreadedBST.(c|cpp|java|py)   # Node and ThreadedBST class, menu loop
├── docs/
│   ├── problem_statement.pdf         # Problem definition
│   ├── algorithms.md                 # Insert, successor, traversal, thread display
│   └── flowcharts.pdf                # Flowcharts for each algorithm
└── README.md
```

## Getting Started

### Prerequisites
- A C++, Java, or Python 3 compiler/interpreter

### Run
```bash
# Python example
python3 src/ThreadedBST.py
```

## Usage

```
===== Book ID Lookup System =====
1. Insert Book ID
2. Find Inorder Successor
3. Display Inorder Traversal
4. Display Threads
5. Exit
Enter choice: 1
Enter Book ID: 50
Book ID 50 inserted successfully.
```

## Complexity

| Operation | Time | Extra space |
|---|---|---|
| Insert | O(h) | O(1) |
| Find inorder successor | O(h) | O(1) |
| Inorder traversal | O(n) | O(1) |
| Thread display | O(n) | O(1) |

`h` is the tree height (`O(log n)` on average, `O(n)` worst case) and `n` is the number of books.

## Constraints

- Book IDs are unique positive integers.
- Data is held in memory and is not saved between runs.
- Deletion is not supported in this version.

## Future Scope

- Delete a book and rebalance threads
- Store titles, authors, and shelf locations
- Save and load the catalogue from a file
- Search by title or author with a GUI front end

## License

This project is intended for academic use. Add your preferred license here. 

# Public Transport Depot Communication Network Using Prim's Algorithm

 Project Overview

The Public Transport Depot Communication Network project aims to connect multiple public transport depots through a communication network at the minimum possible total cost.

Each depot is represented as a vertex in a weighted, undirected graph, and each possible communication link between two depots is represented as an edge with a weight indicating the installation cost.

Prim's Algorithm is used to construct a Minimum Spanning Tree (MST), which connects all depots with the minimum total edge weight without forming any cycles.

 Objectives

- Represent public transport depots as vertices in a graph.
- Represent communication links using weighted edges.
- Apply Prim's Algorithm to find the Minimum Spanning Tree.
- Minimize the total cost of establishing communication links.
- Ensure that all depots are connected through the network.
- Understand the practical application of graph algorithms in network design.

Technologies Used

- Programming Language: C++ / Python / Java (depending on implementation)
- Algorithm: Prim's Minimum Spanning Tree Algorithm
- Data Structure: Weighted graph, adjacency matrix or adjacency list
- Concepts: Graph theory, greedy algorithms, minimum spanning trees

Problem Statement

A public transport authority operates several depots across a city. These depots need to communicate with one another to exchange information about vehicle schedules, routes, fleet availability, and operational updates.

Establishing direct communication links between every pair of depots may be expensive. The objective is to identify a set of communication links that connects all depots while minimizing the overall installation cost.

Prim's Algorithm solves this problem by repeatedly selecting the minimum-weight edge that connects a depot already in the network to a depot that has not yet been connected.

How the Algorithm Works

1. Select a starting depot.
2. Mark the selected depot as part of the network.
3. Find the minimum-weight edge connecting a selected depot to an unselected depot.
4. Add that edge and the newly connected depot to the network.
5. Repeat until all depots are connected.
6. Calculate the sum of the selected edge weights to obtain the minimum total cost.

 Example Network

Consider five public transport depots:

- Depot A
- Depot B
- Depot C
- Depot D
- Depot E

Possible communication links and their installation costs are shown below.

Communication Link| Cost
A – B| 2
A – C| 3
B – C| 1
B – D| 4
C – D| 5
C – E| 6
D – E| 2
B – E| 7

Expected Minimum Spanning Tree

One possible Minimum Spanning Tree contains these links:

Selected Link| Cost
B – C| 1
A – B| 2
D – E| 2
B – D| 4
Total Cost| 9

All five depots are connected using four communication links, and the total installation cost is 9 units.

# 📊 Algorithm Analysis

Let:

- (V) = number of depots (vertices)
- (E) = number of possible communication links (edges)

The time complexity depends on the graph representation and implementation.

Implementation| Time Complexity
Adjacency matrix| (O(V^2))
Adjacency list with a binary min-heap| (O(E\log V))

The space complexity is typically (O(V+E)) for an adjacency-list representation, excluding implementation-specific auxiliary structures.

# 🌟 Applications

- Communication network design for public transport depots.
- Minimizing infrastructure installation costs.
- Planning connections between railway stations and bus terminals.
- Designing computer and telecommunications networks.
- Connecting distributed operational facilities.
- Learning graph algorithms and greedy optimization techniques.

# ✅ Advantages

- Minimizes the total cost of connecting all depots.
- Avoids unnecessary communication links and cycles.
- Provides an efficient solution for connected, weighted, undirected graphs.
- Can be adapted to different graph representations.
- Demonstrates a practical use of Minimum Spanning Trees.

 # ⚠️ Limitations

- The basic algorithm assumes an undirected graph with meaningful edge weights.
- If the graph is disconnected, a single spanning tree covering all depots does not exist.
- The model minimizes the sum of link costs; it does not automatically optimize latency, bandwidth, reliability, or network redundancy.
- Real-world implementation requires accurate cost estimates and infrastructure constraints.

🚀 How to Run

1.  # repository of Graph:
   
   GRAPH  https://github.com/VishalThorat07/DSA-PROJECT-CCE/tree/main/Graph

2. Navigate to the project directory:
   
   cd YOUR-REPOSITORY

3. Compile and run the program according to the programming language used.
   
   For C++, for example:
   
   g++ main.cpp -o depot_network
./depot_network
   
   For Python, if the implementation is in "main.py":
   
   python main.py
   
   For Java, compile and run the appropriate class containing the "main" method.

# Project Structure

public-transport-depot-network/
├── README.md
├── main.cpp
└── .gitignore

The structure above is an example for a C++ implementation. Update the filenames to match your actual repository.

#  Future Enhancements

- Accept depot names and link costs as user input.
- Display the selected communication links and minimum total cost.
- Visualize the network using a graph visualization library.
- Compare Prim's Algorithm with Kruskal's Algorithm.
- Support disconnected graphs and report when a complete network is impossible.
- Extend the model to consider link reliability and communication latency.

# Conclusion

The Public Transport Depot Communication Network project demonstrates how Prim's Algorithm can be used to connect multiple depots with minimum total installation cost.

By modeling depots as vertices and communication links as weighted edges, the algorithm identifies a Minimum Spanning Tree that connects every depot without unnecessary cycles.

This project illustrates the practical application of graph theory and greedy algorithms to infrastructure planning and cost optimization.

 Author

# VISHAL THORAT

https://github.com/VishalThorat07?tab=repositories

---

This project is developed for educational purposes to demonstrate graph representation, Prim's Algorithm, and Minimum Spanning Trees.

