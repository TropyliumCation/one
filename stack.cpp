//array list implementation of stack
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


//linked list implementation of stack

#include<iostream>
using namespace std;

class Node{
	public:
	int val;
	Node *next;
	Node(int data){
		next=NULL;
		val=data;
	}
};
class Stack{
public:
Node *head;
int size;

Stack(){
head=NULL;
size=0;
}

void push(int element){
	Node *temp= new Node(element);
	temp->next=head;
	head=temp;
	size++;
}
void pop(){
	if(head!=NULL){
		head=head->next;
		size--;
	}
	else{
		cout << "STACK UNDERFLOW" << endl;
	}
}
int peek(){
	if(head!=NULL){
		return head->val;
	}
	else{
		cout << "STACK is empty" << endl;
		return -1;
	}
	
}
bool empty(){
	if(head==NULL){
		return true;
	}
	else{
		return false;
	}
}
int length(){
	return size;
}
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.peek() << endl;
	cout << s.length() << endl;
	s.pop();
	s.pop();
	cout << s.peek() << endl;
	s.pop();
	if(s.empty()){
		cout << "Stack is empty" << endl;
	}
	else{
		cout << "Stack is not empty" << endl;
	}

	return 0;
}