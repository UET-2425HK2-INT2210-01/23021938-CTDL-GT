#include <iostream>
const int MAX_SIZE = 100; // K�ch th�?c t?i �a c?a h�ng �?i
using namespace std;

class Queue {
private:
    int arr[MAX_SIZE]; // M?ng �? l�u tr? ph?n t?
    int front, rear;   // Ch? s? �?u v� cu?i h�ng �?i
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Ki?m tra h�ng �?i c� r?ng kh�ng
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Ki?m tra h�ng �?i c� �?y kh�ng
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Th�m ph?n t? v�o h�ng �?i (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // X�a ph?n t? kh?i h�ng �?i (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    // Xem ph?n t? �?u ti�n c?a h�ng �?i (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Hi?n th? h�ng �?i
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout << "Front element: " << q.peek() << endl;
    return 0;
}

// K�ch th�?c t?i �a c?a h�ng �?i
// T?o m?ng l�u tr? d? li?u
// Ch? s? �?u v� cu?i h�ng �?i
// Check h�ng �?i c� r?ng kh�ng
// Check h�ng �?i c� �?y kh�ng
// Th�m ph?n t? v�o h�ng �?i (enqueue)
// X�a ph?n t? kh?i h�ng �?i (dequeue)
// Xem ph?n t? �?u ti�n c?a h�ng �?i (peek)
// Hi?n th? h�ng �?i
