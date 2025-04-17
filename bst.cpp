#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int key) {
        value = key;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->value) {
            node->left = insert(node->left, key);
        } else if (key > node->value) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->value == key) {
            return node;
        }
        if (key < node->value) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->value) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->value) {
            root->right = deleteNode(root->right, key);
        } else {

            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right); 
            root->value = temp->value; 
            root->right = deleteNode(root->right, temp->value); 
        }
        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* search(int key) {
        return search(root, key);
    }

    Node* findMin() {
        return findMin(root);
    }

    Node* findMax() {
        return findMax(root);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal: ";
    bst.inorder(); 


    int key = 40;
    Node* result = bst.search(key);
    if (result) {
        cout << "Node " << key << " found." << endl;
    } else {
        cout << "Node " << key << " not found." << endl;
    }


    Node* minNode = bst.findMin();
    Node* maxNode = bst.findMax();
    cout << "Minimum value: " << minNode->value << endl;
    cout << "Maximum value: " << maxNode->value << endl;

    // Delete a node
    bst.deleteNode(20);
    cout << "In-order traversal after deleting 20: ";
    bst.inorder(); 

    return 0;
}
