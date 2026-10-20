# Disaster Response Resource coordination System

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
# Book ID Lookup System using Threaded Binary Search Tree

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
