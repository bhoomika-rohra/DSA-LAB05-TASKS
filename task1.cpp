#include <iostream>
using namespace std;

class Stack {
	int arr[8];
	int top;

public:
	Stack() {
		top = -1;
	}

	void push(int x) {
		if (top == 7) {
			cout << "Stack is full\n";
			return;
		}

		top++;
		arr[top] = x;
		cout << "Top operation: " << arr[top] << endl;
	}

	void undo() {
		if (top == -1) {
			cout << "Stack is empty\n";
			return;
		}

		top--;

		if (top == -1)
			cout << "Top operation: None" << endl;
		else
			cout << "Top operation: " << arr[top] << endl;
	}

	void display() {
		cout << "\nOperations from top to bottom:\n";

		if (top == -1) {
			cout << "Stack is empty\n";
			return;
		}

		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Stack s;

	s.push(12);
	s.push(25);
	s.push(17);
	s.push(31);
	s.push(44);
	s.push(19);

	s.undo();
	s.undo();
	s.undo();

	s.push(52);

	s.undo();
	s.undo();

	s.display();

	s.undo();
	s.undo();
	s.undo();
	s.undo();

	return 0;
}