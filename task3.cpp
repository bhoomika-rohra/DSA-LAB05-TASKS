#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		data=d;
		next=NULL;
	}
};
class Queue {
public:
	Node* front;
	Node* rear;
	int size;
	Queue() {
		front=rear=NULL;
		size=0;
	}
	bool isEmpty() {
		return front == NULL;
	}
	void enqueue(int new_data) {
		Node* node = new Node(new_data);
		if (isEmpty()) {
			front = rear = node;
		} else {
			rear->next = node;
			rear = node;
		}

		size++;
	}
	int dequeue() {
		if (isEmpty()) {
			cout << "Queue Underflow" << endl;
			return -1;
		}

		Node* temp = front;
		int removedData = temp->data;
		front = front->next;

		if (front == NULL) rear = NULL;
		delete temp;

		size--;
		return removedData;
	}
	int getSize(){
	    return size;
	}
	

};
class Stack {
public:
	Node* top;
	int count;
	Stack() {
		top = NULL;
		count = 0;
	}
	void push(int x) {
		Node* temp = new Node(x);
		temp->next = top;
		top = temp;

		count++;
	}
	bool isEmpty() {
        return top == NULL;
    }
	int pop() {
		if (top == NULL) {
			cout << "Stack Underflow" << endl;
			return -1;
		}
		Node* temp = top;
		top = top->next;
		int val = temp->data;
		count--;
		delete temp;
		return val;
	}
};
void reverseFirstK(Queue& q, int k) {

    Stack s;

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    int size = q.getSize();

    for (int i = 0; i < size - k; i++) {
        q.enqueue(q.dequeue());
    }
}
int main() {

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    int k = 3;

    reverseFirstK(q, k);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}