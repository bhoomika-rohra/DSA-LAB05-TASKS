#include <iostream>
using namespace std;

class Node {
public:
    string word;
    Node* next;

    Node(string w) {
        word = w;
        next = NULL;
    }
};

class Stack {
public:
    Node* history;

    Stack() {
        history = NULL;
    }

    void push(string word) {
        Node* n = new Node(word);
        n->next = history;
        history = n;
    }

    string pop() {
        if (history == NULL)
            return "";

        Node* temp = history;
        string word = temp->word;
        history = history->next;
        delete temp;

        return word;
    }

    void clear() {
        while (history != NULL)
            pop();
    }
};

int main() {
    Stack UNDO;
    Stack REDO;

    string document = "";

    UNDO.push("Hello");
    document = "Hello";
    cout << document << endl;

    UNDO.push("World");
    document = document + " World";
    cout << document << endl;

    string word = UNDO.pop();
    REDO.push(word);
    document = "Hello";
    cout << document << endl;

    word = REDO.pop();
    UNDO.push(word);
    document = document + " " + word;
    cout << document << endl;

    word = UNDO.pop();
    REDO.push(word);
    document = "Hello";
    cout << document << endl;

    UNDO.push("There");
    REDO.clear();
    document = document + " There";
    cout << document << endl;

    if (REDO.history != NULL) {
        word = REDO.pop();
        UNDO.push(word);
        document = document + " " + word;
    }

    cout << document << endl;

    return 0;
}