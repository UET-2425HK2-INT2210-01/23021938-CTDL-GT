#include <iostream>
using namespace std;

// Node c?a danh s�ch li�n k?t
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// H�ng �?i s? d?ng danh s�ch li�n k?t
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    // Ki?m tra h�ng �?i c� r?ng kh�ng
    bool isEmpty() {
        return (front == nullptr);
    }

    // Th�m ph?n t? v�o h�ng �?i (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // X�a ph?n t? kh?i h�ng �?i (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    // Xem ph?n t? �?u ti�n c?a h�ng �?i (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Hi?n th? h�ng �?i
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
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

// Khai b�o Node: data v� next 
// Khai b�o Queue: head = tail = nullptr
// Check h�ng �?i c� r?ng kh�ng
// Th�m ph?n t? v�o h�ng �?i (enqueue)
// X�a ph?n t? kh?i h�ng �?i (dequeue)
// Xem ph?n t? �?u ti�n c?a h�ng �?i (peek)
// Hi?n th? h�ng �?i
