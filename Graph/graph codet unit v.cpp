#include <iostream>
#include <string>
#include <limits>
using namespace std;
 
const int MAX = 20;
const int INF = 1000000;
 
string depot[MAX];
int cost[MAX][MAX];
int n = 0;
 
int findDepot(string name) {
    for (int i = 0; i < n; i++) {
        if (depot[i] == name) {
            return i;
        }
    }
    return -1;
}
 
void addDepot() {
    string name;
    cout << "Depot name: ";
    getline(cin, name);
    if (n == MAX) {
        cout << "Network is full!\n";
        return;
    }
    if (findDepot(name) != -1) {
        cout << "Depot already exists!\n";
        return;
    }
    depot[n++] = name;
    cout << "Depot added successfully!\n";
}
 
void displayDepots() {
    if (n == 0) {
        cout << "No depots available!\n";
        return;
    }
    cout << "\n--- Depots ---\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << depot[i] << '\n';
    }
}
 
void addLink() {
    string a, b;
    int c;
    cout << "First depot: ";
    getline(cin, a);
    cout << "Second depot: ";
    getline(cin, b);
    int u = findDepot(a), v = findDepot(b);
    if (u == -1 || v == -1) {
        cout << "Depot not found!\n";
        return;
    }
    if (u == v) {
        cout << "A depot cannot be linked to itself!\n";
        return;
    }
    cout << "Link cost: ";
    if (!(cin >> c) || c <= 0) {
        cout << "Invalid cost!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool exists = (cost[u][v] != 0);
    cost[u][v] = cost[v][u] = c;
    if (exists) {
        cout << "Link cost updated!\n";
    } else {
        cout << "Link added successfully!\n";
    }
}
 
void displayLinks() {
    int count = 0;
    cout << "\n--- Communication Links ---\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0) {
                cout << depot[i] << " <-> " << depot[j]
                     << " : " << cost[i][j] << '\n';
                count++;
            }
        }
    }
    if (count == 0) {
        cout << "No links available!\n";
    } else {
        cout << "Total links: " << count << '\n';
    }
}
 
void prim() {
    if (n == 0) {
        cout << "No depots available!\n";
        return;
    }
    string s;
    cout << "Start depot: ";
    getline(cin, s);
    int start = findDepot(s);
    if (start == -1) {
        cout << "Depot not found!\n";
        return;
    }
 
    int key[MAX], parent[MAX], total = 0, reached = 0;
    bool inMST[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = false;
    }
    key[start] = 0;
 
    cout << "\n--- Prim's Minimum Spanning Tree ---\n";
    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        if (key[u] == INF) {
            break;
        }
        inMST[u] = true;
        reached++;
        if (parent[u] == -1) {
            cout << "Start at " << depot[u] << '\n';
        } else {
            cout << "Link " << depot[parent[u]] << " - " << depot[u]
                 << " (cost " << key[u] << ")\n";
            total += key[u];
        }
        for (int v = 0; v < n; v++) {
            if (cost[u][v] != 0 && !inMST[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }
 
    if (reached < n) {
        cout << "Network is not connected! Only " << reached << " of "
             << n << " depots can be reached.\n";
        return;
    }
    cout << "Minimum total cost = " << total << '\n';
}
 
int main() {
    int c;
    do {
        cout << "\n===== Depot Communication Network =====\n"
             << "1. Add Depot\n"
             << "2. Add Link\n"
             << "3. Display Depots\n"
             << "4. Display Links\n"
             << "5. Apply Prim's Algorithm\n"
             << "6. Exit\n\n"
             << "Choice: ";
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (c) {
            case 1:
                addDepot();
                break;
            case 2:
                addLink();
                break;
            case 3:
                displayDepots();
                break;
            case 4:
                displayLinks();
                break;
            case 5:
                prim();
                break;
            case 6:
                cout << "Program ended.\n\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (c != 6);
    return 0;
}

