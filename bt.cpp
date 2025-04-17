#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;	
	Node *right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
void preorder(Node *root){
	if(root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void postorder(Node *root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
void levelorder(Node *root){
	if(root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if(temp->left != NULL) q.push(temp->left);
		if(temp->right != NULL) q.push(temp->right);
	}
}
void zigzag(Node *root){
	if(root == NULL) return;
	bool flag=true;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		vector<int> row(size);
		for(int i=0; i<size; i++){
			Node *temp = q.front();
			q.pop();
			int index = (flag) ? i : size-i-1;
			row[index] = temp->data;
			if(temp->left != NULL) q.push(temp->left);
			if(temp->right != NULL) q.push(temp->right);
		}
		flag=!flag;
		for(int i=0; i<size; i++) cout << row[i] << " ";
	}
}
void preorder_iterative(Node *root){
	stack<Node*> s;
	s.push(root);
	while(!s.empty()){
		root = s.top();
		s.pop();
		cout << root->data << " ";
		if(root->right != NULL) s.push(root->right);
		if(root->left != NULL) s.push(root->left);
	}
}
void inorder_iterative(Node *root){
	stack<Node*> s;
	while(true){
		if(root != NULL){
			s.push(root);
			root = root->left;
		}
		else{
			if(s.empty()) break;
			root = s.top();
			s.pop();
			cout << root->data << " ";
			root = root->right;
		}
	}
}
void postorder_iterative2(Node *root){
	stack<Node*> s1, s2;
	s1.push(root);
	while(!s1.empty()){
		root = s1.top();
		s1.pop();
		s2.push(root);
		if(root->left != NULL) s1.push(root->left);
		if(root->right != NULL) s1.push(root->right);
	}
	while(!s2.empty()){
		root = s2.top();
		s2.pop();
		cout << root->data << " ";
	}
}
void postorder_iterative(Node *root){
	stack<Node*> s;
	Node *curr = root;
	while(curr!=NULL || !s.empty()){
		if(curr != NULL){
			s.push(curr);
			curr = curr->left;
		}
		else{
			Node *temp = s.top()->right;
			if(temp == NULL){
				temp = s.top();
				s.pop();
				cout << temp->data << " ";
				while(!s.empty() && temp == s.top()->right){
					temp = s.top();
					s.pop();
					cout << temp->data << " ";
				}
			}
			else curr = temp;
		}
	}
}

class diameterOfBT{
	public:
	
					int func(Node* root,int &diameter){
									if(root==nullptr) return 0;
									int leftdiameter=func(root->left,diameter);
									int rightdiameter=func(root->right,diameter);
									diameter=max(leftdiameter+rightdiameter+1,diameter);
	
									return 1+max(leftdiameter,rightdiameter);
					}
					int diameterOfBinaryTree(Node* root) {
									int diameter=0;
									func(root,diameter);
									return diameter-1;
					}
	};


int main(){
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);

	return 0;
}
