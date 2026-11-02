#include <iostream>
#include <queue>
#include <string>
#include <limits>
using namespace std;

struct Patient {
    int token;
    string name;
    int age;
    string problem;
};

queue<Patient> waitingQueue;
int nextToken = 1;

void addPatient() {
    Patient p;
    p.token = nextToken++;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter patient name: ";
    getline(cin, p.name);

    cout << "Enter patient age: ";
    while (!(cin >> p.age) || p.age <= 0) {
        cout << "Please enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter reason for consultation: ";
    getline(cin, p.problem);

    waitingQueue.push(p);  // ENQUEUE: add at the rear
    cout << "\nPatient registered successfully!\n";
    cout << "Token number: " << p.token << "\n";
}

void callNextPatient() {
    if (waitingQueue.empty()) {
        cout << "\nNo patients are waiting.\n";
        return;
    }

    Patient p = waitingQueue.front(); // PEEK at the front
    waitingQueue.pop();               // DEQUEUE from the front

    cout << "\nNow calling patient:\n";
    cout << "Token: " << p.token << "\n";
    cout << "Name: " << p.name << "\n";
    cout << "Age: " << p.age << "\n";
    cout << "Reason: " << p.problem << "\n";
}

void displayQueue() {
    if (waitingQueue.empty()) {
        cout << "\nThe waiting queue is empty.\n";
        return;
    }

    queue<Patient> temp = waitingQueue;
    cout << "\n--- Patients Waiting for Consultation ---\n";
    cout << "Token\tName\t\tAge\tReason\n";
    while (!temp.empty()) {
        Patient p = temp.front();
        temp.pop();
        cout << p.token << "\t" << p.name << "\t\t"
             << p.age << "\t" << p.problem << "\n";
    }
}

void searchPatient() {
    if (waitingQueue.empty()) {
        cout << "\nNo patients are waiting.\n";
        return;
    }

    int wantedToken;
    cout << "\nEnter token number to search: ";
    if (!(cin >> wantedToken)) {
        cout << "Invalid token number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    queue<Patient> temp = waitingQueue;
    while (!temp.empty()) {
        Patient p = temp.front();
        temp.pop();
        if (p.token == wantedToken) {
            cout << "\nPatient found in waiting queue:\n";
            cout << "Token: " << p.token << "\n";
            cout << "Name: " << p.name << "\n";
            cout << "Age: " << p.age << "\n";
            cout << "Reason: " << p.problem << "\n";
            return;
        }
    }
    cout << "\nPatient not found in the waiting queue.\n";
}

int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << " HOSPITAL PATIENT QUEUE MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Register / Add Patient\n";
        cout << "2. Call Next Patient\n";
        cout << "3. Display Waiting Queue\n";
        cout << "4. Search Patient by Token\n";
        cout << "5. Show Number of Waiting Patients\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a number from the menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                callNextPatient();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                searchPatient();
                break;
            case 5:
                cout << "\nPatients waiting: " << waitingQueue.size() << "\n";
                break;
            case 0:
                cout << "\nThank you for using the system.\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
