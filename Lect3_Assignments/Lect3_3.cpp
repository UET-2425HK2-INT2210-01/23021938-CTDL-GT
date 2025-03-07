#include <iostream>
const int MAX_SIZE = 100; // Kích thý?c t?i ða c?a hàng ð?i
using namespace std;

class Queue {
private:
    int arr[MAX_SIZE]; // M?ng ð? lýu tr? ph?n t?
    int front, rear;   // Ch? s? ð?u và cu?i hàng ð?i
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Ki?m tra hàng ð?i có r?ng không
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Ki?m tra hàng ð?i có ð?y không
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Thêm ph?n t? vào hàng ð?i (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Xóa ph?n t? kh?i hàng ð?i (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    // Xem ph?n t? ð?u tiên c?a hàng ð?i (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Hi?n th? hàng ð?i
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

// Kích thý?c t?i ða c?a hàng ð?i
// T?o m?ng lýu tr? d? li?u
// Ch? s? ð?u và cu?i hàng ð?i
// Check hàng ð?i có r?ng không
// Check hàng ð?i có ð?y không
// Thêm ph?n t? vào hàng ð?i (enqueue)
// Xóa ph?n t? kh?i hàng ð?i (dequeue)
// Xem ph?n t? ð?u tiên c?a hàng ð?i (peek)
// Hi?n th? hàng ð?i
