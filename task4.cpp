#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int SIZE = 6;
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
            return true;
        return false;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is FULL!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        items[rear] = element;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Boarded: " << items[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Final passengers: ";

        int i = front;

        while (true) {
            cout << items[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }

    void showPositions() {
        cout << "Front position: " << front << endl;
        cout << "Rear position: " << rear << endl;
    }
};

int main() {

    CircularQueue q;
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    q.dequeue();
    q.dequeue();

    q.enqueue(110);

    q.dequeue();

    q.enqueue(111);
    q.enqueue(112);

    q.display();
    q.showPositions();

    return 0;
}