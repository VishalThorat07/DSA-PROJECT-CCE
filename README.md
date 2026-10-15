# Disaster Management Resource Management System

A menu-driven **C++ console application** for managing disaster-relief
resources such as water bottles, food packets, medicines, and first-aid
kits. It allows users to add resources, view stock, register relief
requests, dispatch resources, undo the last dispatch, and view activity
history.

## Table of Contents
## Project Resources

- [Algorithm](https://github.com/VishalThorat07/DSA-PROJECT-CCE/blob/main/linked%20list/algorithm/Algorithm_Disaster_Management.pdf)

- [Flowchart PDF](linked%20list/Flowchart/Flowchart_Disaster_Management.pdf)

- [Output PDF](linked%20list/output/disaster%20response%20output.pdf)

- [Source Code](linked%20list/code%201/disaster%20response%20resource%20coordination%20system.cpp)
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

## Data Structures Used

  -----------------------------------------------------------------------
  Data structure                      Purpose
  ----------------------------------- -----------------------------------
  `struct Resource`                   Stores a resource name and
                                      available quantity.

  `struct Request`                    Stores the requested resource,
                                      quantity, and request status.

  `vector`                            Stores resources, requests, and
                                      activity history dynamically.

  `struct DispatchRecord`             Stores enough information to undo
                                      the most recent dispatch.
  -----------------------------------------------------------------------

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
 
