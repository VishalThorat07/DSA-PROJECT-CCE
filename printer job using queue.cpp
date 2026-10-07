#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> printerQueue;
    int choice;
    string job;

    do {
        cout << "\n===== Printer Queue =====\n";
        cout << "1. Add Print Job\n";
        cout << "2. Print Next Job\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter print job name: ";
                cin >> job;
                printerQueue.push(job);
                cout << "Print job added successfully.\n";
                break;

            case 2:
                if (printerQueue.empty()) {
                    cout << "Printer queue is empty.\n";
                } else {
                    cout << "Printing: " << printerQueue.front() << endl;
                    printerQueue.pop();
                    cout << "Print job completed.\n";
                }
                break;

            case 3:
                if (printerQueue.empty()) {
                    cout << "Printer queue is empty.\n";
                } else {
                    queue<string> temp = printerQueue;

                    cout << "\nJobs in Printer Queue:\n";
                    while (!temp.empty()) {
                        cout << "- " << temp.front() << endl;
                        temp.pop();
                    }
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
