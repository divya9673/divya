#include <iostream>
using namespace std;
struct Node {
    int empID;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertSorted(int id) {
        Node* newNode = new Node();
        newNode->empID = id;
        newNode->prev = nullptr;
        newNode->next = nullptr;

         if (head == nullptr) {
            head = newNode;
            return;
        }

         if (id < head->empID) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->empID < id) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    int countEmployees() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteEmployee(int id) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

         while (temp != nullptr && temp->empID != id) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Employee ID " << id << " not found.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
        } else {
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Employee ID " << id << " deleted successfully.\n";
    }

    void display() {
        Node* temp = head;
        cout << "Employee IDs: ";
        while (temp != nullptr) {
            cout << temp->empID << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, id;

    while (true) {
        cout << "\n Employee Database Menu \n";
        cout << "1. Insert Employee ID\n";
        cout << "2. Display All Employee IDs\n";
        cout << "3. Count Employees\n";
        cout << "4. Delete Employee ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID to insert: ";
            cin >> id;
            dll.insertSorted(id);
            break;
        case 2:
            dll.display();
            break;
        case 3:
            cout << "Total Employees: " << dll.countEmployees() << "\n";
            break;
        case 4:
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            dll.deleteEmployee(id);
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
