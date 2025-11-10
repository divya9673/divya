 #include <iostream>
#include <string>
using namespace std;

class Node {
public:
    long long prn;
    string name;
    Node* next;

    Node(long long p, string n) {
        prn = p;
        name = n;
        next = NULL;
    }
};

class Club {
public:
    Node* head;

    Club() {
        head = NULL;
    }

    // Insert at beginning (President)
    void insertAtBeginning(long long prn, string name) {
        Node* newnode = new Node(prn, name);
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
        cout << "Inserted at beginning (President).\n";
    }

    // Insert at end (Secretary)
    void insertAtEnd(long long prn, string name) {
        Node* newnode = new Node(prn, name);
        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
        cout << "Inserted at end (Secretary).\n";
    }

    // Insert after a given PRN (Member)
    void insertAfter(long long afterPRN, long long prn, string name) {
        if (head == NULL) {
            cout << "List empty. Insert President first.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->prn != afterPRN) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "PRN not found.\n";
            return;
        }
        Node* newnode = new Node(prn, name);
        newnode->next = temp->next;
        temp->next = newnode;
        cout << "Inserted after PRN " << afterPRN << ".\n";
    }

    // Delete from beginning (President)
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted President: " << temp->prn << " " << temp->name << "\n";
        delete temp;
    }

    // Delete from end (Secretary)
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        if (head->next == NULL) {
            cout << "Deleted Secretary: " << head->prn << " " << head->name << "\n";
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        cout << "Deleted Secretary: " << temp->prn << " " << temp->name << "\n";
        prev->next = NULL;
        delete temp;
    }

    // Delete by PRN (Member)
    void deleteByPRN(long long prn) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        if (head->prn == prn) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "PRN not found.\n";
            return;
        }
        prev->next = temp->next;
        cout << "Deleted Member: " << temp->prn << " " << temp->name << "\n";
        delete temp;
    }

    // Count total members
    int computeTotal() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "\nPRN\tName\n";
        cout << "-------------------\n";
        while (temp != NULL) {
            cout << temp->prn << "\t" << temp->name << "\n";
            temp = temp->next;
        }
        cout << "-------------------\n";
        cout << "Total Members: " << computeTotal() << "\n";
    }

    // Concatenate two lists
    void concatenate(Club& other) {
        if (head == NULL) {
            head = other.head;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = other.head;
        cout << "Lists concatenated.\n";
    }
};

// ---------------- Main ------------------
int main() {
    Club divA, divB;
    int choice;
    string name;
    long long prn, afterPRN;

    do {
        cout << "CLUB MENU ";
        cout << "1. Insert President (Beginning)";
        cout << "2. Insert Secretary (End)";
        cout << "3. Insert Member (After PRN)";
        cout << "4. Delete President (Beginning)";
        cout << "5. Delete Secretary (End)";
        cout << "6. Delete Member (By PRN)";
        cout << "7. Display Members";
        cout << "8. Count Members";
        cout << "9. Concatenate Division B into A";
        cout << "0. Exit";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            divA.insertAtBeginning(prn, name);
            break;
        case 2:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            divA.insertAtEnd(prn, name);
            break;
        case 3:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            cout << "Enter PRN after which to insert: ";
            cin >> afterPRN;
            divA.insertAfter(afterPRN, prn, name);
            break;
        case 4:
            divA.deleteAtBeginning();
            break;
        case 5:
            divA.deleteAtEnd();
            break;
        case 6:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            divA.deleteByPRN(prn);
            break;
        case 7:
            divA.display();
            break;
        case 8:
            cout << "Total Members: " << divA.computeTotal() << "\n";
            break;
        case 9:
            cout << "Enter President of Div B (PRN & Name): ";
            cin >> prn >> name;
            divB.insertAtBeginning(prn, name);
            cout << "Enter Secretary of Div B (PRN & Name): ";
            cin >> prn >> name;
            divB.insertAtEnd(prn, name);
            divA.concatenate(divB);
            break;
        case 0:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!";
        }
    } while (choice != 0);

    return 0;
}
