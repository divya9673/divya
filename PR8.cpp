#include <iostream>
using namespace std;

#define MAX 5  // Maximum number of orders the restaurant can accept

class CircularQueue {
    int orders[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Cannot place order " << orderID << ". Queue is full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        orders[rear] = orderID;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << " No orders to serve.\n";
            return;
        }

        cout << " Order " << orders[front] << " served.\n";

        if (front == rear) {
            // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << " Current Orders in Queue: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue restaurant;
    int choice, orderID;

    cout << "\n Restaurant Order Management System\n";
    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                restaurant.placeOrder(orderID);
                break;

            case 2:
                restaurant.serveOrder();
                break;

            case 3:
                restaurant.displayOrders();
                break;

            case 4:
                cout << "Exiting... Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
} 
