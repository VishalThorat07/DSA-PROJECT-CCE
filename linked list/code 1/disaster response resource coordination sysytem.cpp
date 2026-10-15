#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Resource {
    string name;
    int qty;
    Resource* next;

    Resource(string n, int q) {
        name = n;
        qty = q;
        next = NULL;
    }
};

struct Request {
    string loc, res;
    int qty;
    Request* next;

    Request(string l, string r, int q) {
        loc = l;
        res = r;
        qty = q;
        next = NULL;
    }
};

Resource* inventory = NULL;
Request *front = NULL, *rear = NULL, *history = NULL;

void addResource() {
    string n;
    int q;

    cout << "Resource name: ";
    getline(cin, n);

    cout << "Quantity: ";
    if (!(cin >> q) || q < 0) {
        cout << "Invalid quantity!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Resource* p = inventory; p != NULL; p = p->next) {
        if (p->name == n) {
            p->qty += q;
            cout << "Resource quantity updated!\n";
            return;
        }
    }

    Resource* p = new Resource(n, q);
    p->next = inventory;
    inventory = p;

    cout << "Resource added successfully!\n";
}

void displayResources() {
    if (inventory == NULL) {
        cout << "No resources available!\n";
        return;
    }

    cout << "\n--- Available Resources ---\n";

    for (Resource* p = inventory; p != NULL; p = p->next) {
        cout << p->name << " - " << p->qty << '\n';
    }
}

void registerRequest() {
    string l, r;
    int q;

    cout << "Location: ";
    getline(cin, l);

    cout << "Resource needed: ";
    getline(cin, r);

    cout << "Quantity: ";

    if (!(cin >> q) || q <= 0) {
        cout << "Invalid quantity!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Request* p = new Request(l, r, q);

    if (rear == NULL) {
        front = rear = p;
    } else {
        rear->next = p;
        rear = p;
    }

    cout << "Request registered successfully!\n";
}

void displayRequests() {
    if (front == NULL) {
        cout << "No pending requests!\n";
        return;
    }

    cout << "\n--- Pending Requests ---\n";

    for (Request* p = front; p != NULL; p = p->next) {
        cout << p->loc << " needs "
             << p->qty << " " << p->res << '\n';
    }
}

void dispatch() {
    if (front == NULL) {
        cout << "No requests!\n";
        return;
    }

    Resource* r = inventory;

    while (r != NULL && r->name != front->res) {
        r = r->next;
    }

    if (r == NULL || r->qty < front->qty) {
        cout << "Resource unavailable or insufficient!\n";
        return;
    }

    r->qty -= front->qty;

    Request* p = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    p->next = history;
    history = p;

    cout << "Dispatched " << p->qty << " "
         << p->res << " to " << p->loc << '\n';
}

void undo() {
    if (history == NULL) {
        cout << "Nothing to undo!\n";
        return;
    }

    Request* p = history;
    history = history->next;

    for (Resource* r = inventory; r != NULL; r = r->next) {
        if (r->name == p->res) {
            r->qty += p->qty;
            break;
        }
    }

    p->next = front;
    front = p;

    if (rear == NULL) {
        rear = p;
    }

    cout << "Last dispatch undone!\n";
}

void displayHistory() {
    if (history == NULL) {
        cout << "No dispatch history!\n";
        return;
    }

    cout << "\n--- Dispatch History ---\n";

    for (Request* p = history; p != NULL; p = p->next) {
        cout << p->loc << " received "
             << p->qty << " " << p->res << '\n';
    }
}

int main() {
    int c;

    do {
        cout << "\n===== Resource Management System =====\n"
             << "1. Add Resource\n"
             << "2. Display Resources\n"
             << "3. Register Request\n"
             << "4. Display Requests\n"
             << "5. Dispatch\n"
             << "6. Undo Last Dispatch\n"
             << "7. Display History\n"
             << "8. Exit\n"
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
                addResource();
                break;

            case 2:
                displayResources();
                break;

            case 3:
                registerRequest();
                break;

            case 4:
                displayRequests();
                break;

            case 5:
                dispatch();
                break;

            case 6:
                undo();
                break;

            case 7:
                displayHistory();
                break;

            case 8:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (c != 8);

    return 0;
}
