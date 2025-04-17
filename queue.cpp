#include <iostream>
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
	
					void enqueue(int item) {
									if (count == capacity)
													resize();
	
									rear++;
									arr[rear] = item;
									count++;
					}
	
					void dequeue() {
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

	int main(){
		Queue q;
		q.enqueue(8);
		q.enqueue(3);
		q.enqueue(9);
		cout << q.size() << endl;
		q.dequeue();
		q.dequeue();
		q.dequeue();
		if(q.isEmpty()){
			cout << "Queue is empty" << endl;
		}
		else{
			cout << "Queue is not empty" << endl;
		}
	
		return 0;
	}