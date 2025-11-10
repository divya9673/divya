#include <iostream>
using namespace std;

#define MAX 5  // Maximum queue size

class TicketDeque {
    string queue[MAX];
    int front, rear;

public:
    TicketDeque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

  
    void addRegularCustomer(string name) {
        if (isFull()) {
            cout << "Queue is full! Cannot add regular customer.\n";
            return;
        }

        if (front == -1) { 
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1)
            rear = 0;
        else
            rear++;

        queue[rear] = name;
        cout << "Regular customer '" << name << "' added at the rear.\n";
    }

  
    void addVIPCustomer(string name) {
        if (isFull()) {
            cout << "Queue is full! Cannot add VIP customer.\n";
            return;
        }

        if (front == -1) { // First customer
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = MAX - 1;
        else
            front--;

        queue[front] = name;
        cout << "VIP customer '" << name << "' added at the front.\n";
    }


    void serveCustomer() {
        if (isEmpty()) {
            cout << "No customers to serve.\n";
            return;
        }

        cout << "Serving customer: " << queue[front] << endl;

        if (front == rear) {
            // Queue becomes empty
            front = -1;
            rear = -1;
        } else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }

    // Display the queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Current Queue (Front → Rear): ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

// MAIN FUNCTION 
int main() {
    TicketDeque ticketSystem;
    int choice;
    string name;

    cout << "Online Ticket Reservation System \n";
    do {
        cout << "1. Add Regular Customer (Rear)\n"
             << "2. Add VIP Customer (Front)\n"
             << "3. Serve Customer (Front)\n"
             << "4. Display Queue\n"
             << "5. Check if Queue is Full\n"
             << "6. Check if Queue is Empty\n"
             << "7. Exit\n"
             << "Enter your choice: \n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                ticketSystem.addRegularCustomer(name);
                break;

            case 2:
                cout << "Enter VIP customer name: ";
                cin >> name;
                ticketSystem.addVIPCustomer(name);
                break;

            case 3:
                ticketSystem.serveCustomer();
                break;

            case 4:
                ticketSystem.displayQueue();
                break;

            case 5:
                if (ticketSystem.isFull())
                    cout << "Queue is FULL.\n";
                else
                    cout << "Queue is NOT full.\n";
                break;

            case 6:
                if (ticketSystem.isEmpty())
                    cout << " Queue is EMPTY.\n";
                else
                    cout << " Queue is NOT empty.\n";
                break;

            case 7:
                cout << "Exiting... Thank you for using our system!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
