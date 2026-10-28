#include <iostream>
using namespace std;

#define V 5
#define INF 99999

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool visited[V] = {false};
    int totalCost = 0;

    // Initialize keys and parents
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    // Start from Depot 1
    key[0] = 0;

    for (int count = 0; count < V; count++) {
        int min = INF;
        int u = -1;

        // Find the minimum-cost unvisited depot
        for (int i = 0; i < V; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        if (u == -1) {
            cout << "Network is disconnected!" << endl;
            return;
        }

        visited[u] = true;

        // Update adjacent depots
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree:\n";
    cout << "Connection\tCost\n";

    for (int i = 1; i < V; i++) {
        cout << "Depot " << parent[i] + 1
             << " - Depot " << i + 1
             << "\t" << key[i] << endl;

        totalCost += key[i];
    }

    cout << "Total minimum cost = "
         << totalCost << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
