#include <iostream>
using namespace std;

struct Node {
    int bookID;
    Node *left, *right;
    bool lthread, rthread;

    Node(int id) {
        bookID = id;
        left = right = NULL;
        lthread = rthread = true;
    }
};

class ThreadedBST {
    Node *root;

public:
    ThreadedBST() {
        root = NULL;
    }

    void insert(int id) {
        Node *ptr = root;
        Node *parent = NULL;

        while (ptr != NULL) {
            if (id == ptr->bookID) {
                cout << "Duplicate Book ID not allowed.\n";
                return;
            }

            parent = ptr;

            if (id < ptr->bookID) {
                if (!ptr->lthread)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (!ptr->rthread)
                    ptr = ptr->right;
                else
                    break;
            }
        }

        Node *temp = new Node(id);

        if (parent == NULL) {
            root = temp;
        }
        else if (id < parent->bookID) {
            temp->left = parent->left;
            temp->right = parent;

            parent->lthread = false;
            parent->left = temp;
        }
        else {
            temp->right = parent->right;
            temp->left = parent;

            parent->rthread = false;
            parent->right = temp;
        }

        cout << "Book ID inserted successfully.\n";
    }

    Node* inorderSuccessor(Node *ptr) {
        if (ptr->rthread)
            return ptr->right;

        ptr = ptr->right;

        while (ptr != NULL && !ptr->lthread)
            ptr = ptr->left;

        return ptr;
    }

    Node* search(int id) {
        Node *ptr = root;

        while (ptr != NULL) {
            if (id == ptr->bookID)
                return ptr;

            if (id < ptr->bookID) {
                if (ptr->lthread)
                    return NULL;

                ptr = ptr->left;
            }
            else {
                if (ptr->rthread)
                    return NULL;

                ptr = ptr->right;
            }
        }

        return NULL;
    }

    void findSuccessor(int id) {
        Node *ptr = search(id);

        if (ptr == NULL) {
            cout << "Book ID not found.\n";
            return;
        }

        Node *succ = inorderSuccessor(ptr);

        cout << "Book ID: " << id << "\n";

        if (succ != NULL)
            cout << "Inorder Successor: "
                 << succ->bookID << "\n";
        else
            cout << "No inorder successor (last book).\n";
    }

    void inorderTraversal() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }

        Node *ptr = root;

        while (!ptr->lthread)
            ptr = ptr->left;

        cout << "Inorder Book IDs: ";

        while (ptr != NULL) {
            cout << ptr->bookID << " ";
            ptr = inorderSuccessor(ptr);
        }

        cout << "\n";
    }

    void displayThreads() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }

        Node *ptr = root;

        while (!ptr->lthread)
            ptr = ptr->left;

        cout << "\nThread Information:\n";
        cout << "Book ID\tLeft Pointer\tRight Pointer\n";

        while (ptr != NULL) {
            cout << ptr->bookID << "\t";

            if (ptr->lthread) {
                if (ptr->left != NULL)
                    cout << "Thread -> " << ptr->left->bookID;
                else
                    cout << "NULL";
            }
            else {
                cout << "Child -> " << ptr->left->bookID;
            }

            cout << "\t";

            if (ptr->rthread) {
                if (ptr->right != NULL)
                    cout << "Thread -> " << ptr->right->bookID;
                else
                    cout << "NULL";
            }
            else {
                cout << "Child -> " << ptr->right->bookID;
            }

            cout << "\n";

            ptr = inorderSuccessor(ptr);
        }
    }
};

int main() {
    ThreadedBST bst;
    int choice, id;

    do {
        cout << "\n--- Book ID Lookup System ---\n";
        cout << "1. Insert Book ID\n";
        cout << "2. Find Inorder Successor\n";
        cout << "3. Display Inorder Traversal\n";
        cout << "4. Display Threads\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                bst.insert(id);
                break;

            case 2:
                cout << "Enter Book ID: ";
                cin >> id;
                bst.findSuccessor(id);
                break;

            case 3:
                bst.inorderTraversal();
                break;

            case 4:
                bst.displayThreads();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
