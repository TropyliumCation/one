#include<iostream>
#include<queue>
using namespace std;

class Queue {
public:
    int* arr;
    int front, rear, capacity, count;

    Queue(int size = 10) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    void resize() {
        capacity *= 2;
        int* newarr = new int[capacity];
        for (int i = 0; i < count; i++) {
            newarr[i] = arr[(front + i) % capacity];
        }
        delete[] arr;
        arr = newarr;
        front = 0;
        rear = count - 1;
    }

    void push(int item) {
        if (count == capacity)
            resize();

        rear++;
        arr[rear] = item;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "QUEUE UNDERFLOW" << endl;
            return;
        }
        front++;
        count--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (count == 0);
    }

    int size() {
        return count;
    }
};

class Stack {
public:
    Queue q1;
    Queue q2;

    Stack() {}

    void push(int x) {
					while (!q1.isEmpty())
					{
						q2.push(q1.peek());
						q1.pop();
					}
					q1.push(x);
					while (!q2.isEmpty())
					{
						q1.push(q2.peek());
						q2.pop();
					}
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "STACK UNDERFLOW" << endl;
        } else {
            q1.pop();
        }
    }

    int peek() {
        if (q1.isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.peek();
    }

    bool empty() {
        return q1.isEmpty();
    }

    int size() {
        return q1.size();
    }

    void print() {
        if (empty()) {
            cout << "Stack is empty" << endl;
        } else {
            Queue temp = q1;
            for (int i = 0; i < temp.size(); i++) {
                cout << temp.peek() << " ";
                temp.push(temp.peek());
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(20);
    s.print();
    cout << "Top: " << s.peek() << endl;
    s.pop();
    s.print();
    s.pop();
    s.pop();
    s.pop(); 
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
