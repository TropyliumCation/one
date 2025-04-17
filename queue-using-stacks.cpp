#include<iostream>
using namespace std;


class Stack{
public:
int* arr;
int capacity;
int top;

Stack(int oldcapacity=10){
capacity=oldcapacity;
arr=new int[capacity];
top=-1;
}
void resize() {
        capacity *= 2;
        int* newarr = new int[capacity];

        for (int i = 0; i <=top; i++) {
            newarr[i] = arr[i];
        }

        delete[] arr;
        arr = newarr;
    }
void push(int element){
      if(top+1==capacity){
      	 resize();
      }
      top++;
      arr[top]=element;
}
void pop(){
	if(top>=0){
		top--;
	}
	else{
		cout << "STACK UNDERFLOW" << endl;
	}
}
int peek(){
	if(top>=0){
		return arr[top];
	}
	else{
		cout << "STACK is empty" << endl;
		return -1;
	}
	
}
bool empty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}
int size(){
	return top+1;
}
};
class Queue{
public:
Stack s;

Queue(){
}
void enqueue(int element){
	s.push(element);
}
void dequeue(){
	Stack temp;
	while(s.size()!=1){
		temp.push(s.peek());
		s.pop();
	}
	s.pop();
	while(!temp.empty()){
		s.push(temp.peek());
		temp.pop();
	}


}
void print(){
	if(s.empty()){
		cout << "Queue is empty" << endl;
	}
	else{
		Stack temp;
		while(!s.empty()){
			temp.push(s.peek());
			s.pop();
		}
		while(!temp.empty()){
			cout << temp.peek() << " ";
			s.push(temp.peek());
			temp.pop();
		}
		cout << endl;
	}
}

bool isEmpty(){
	if(s.empty()){
		return true;
	}
	else{
		return false;
	}
}
int length(){
	return s.size();
}
};
int main(){
	Queue q;
	q.enqueue(8);
	q.enqueue(3);
	q.enqueue(9);
	q.print();
	cout << q.length() << endl;
	q.dequeue();
	q.dequeue();
	q.print();
	q.dequeue();
	if(q.isEmpty()){
		cout << "Queue is empty" << endl;
	}
	else{
		cout << "Queue is not empty" << endl;
	}

	return 0;
}
