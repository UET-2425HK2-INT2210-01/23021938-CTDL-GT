#include <iostream>
using namespace std;

// Node c?a danh sách liên k?t
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Hàng ð?i s? d?ng danh sách liên k?t
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    // Ki?m tra hàng ð?i có r?ng không
    bool isEmpty() {
        return (front == nullptr);
    }

    // Thêm ph?n t? vào hàng ð?i (enqueue)
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

    // Xóa ph?n t? kh?i hàng ð?i (dequeue)
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

    // Xem ph?n t? ð?u tiên c?a hàng ð?i (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Hi?n th? hàng ð?i
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

// Khai báo Node: data và next 
// Khai báo Queue: head = tail = nullptr
// Check hàng ð?i có r?ng không
// Thêm ph?n t? vào hàng ð?i (enqueue)
// Xóa ph?n t? kh?i hàng ð?i (dequeue)
// Xem ph?n t? ð?u tiên c?a hàng ð?i (peek)
// Hi?n th? hàng ð?i
