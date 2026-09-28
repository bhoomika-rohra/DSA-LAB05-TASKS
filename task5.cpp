#include <iostream>
using namespace std;

class MyQueue {
public:
    char incoming[100];
    char outgoing[100];

    int top1;
    int top2;

    MyQueue() {
        top1 = -1;
        top2 = -1;
    }

    void enqueue(char item) {
        top1++;
        incoming[top1] = item;
    }

    char dequeue() {

        if (top2 == -1) {

            while (top1 != -1) {
                top2++;
                outgoing[top2] = incoming[top1];
                top1--;
            }
        }

        char item = outgoing[top2];
        top2--;

        return item;
    }
};

int main() {

    MyQueue q;

    q.enqueue('A');   
    q.enqueue('B');   

    cout << q.dequeue() << endl;   

    q.enqueue('C');   

    cout << q.dequeue() << endl;   
    cout << q.dequeue() << endl;   

    return 0;
}