#include <iostream>

class Node {
    int data;
    Node* lchild;
    Node* rchild;
    int weight;
public:
    Node(int k){
        data = k;
        lchild = nullptr;
        rchild = nullptr;
        weight = 1;
    }
    Node* insertR(int k){
        if (this == nullptr) {
            return new Node(k);
        }
        else if (this->data > k) {
            Node* createdNode = this->lchild->insertR(k);
            this->lchild = createdNode;
            return this;
        }
        else if (this->data < k) {
            Node* createdNode = this->rchild->insertR(k);
            this->rchild = createdNode;
            return this;
        }
        else if (this->data == k) {
            this->weight = this->weight + 1;
        }
        return nullptr;
    }
    void inOrder(){
        if (this == nullptr) {
            return;
        }
        this->lchild->inOrder();
        std::cout << this->data << ", ";
        this->rchild->inOrder();
    }
    bool searchR(int k){
        if (this == nullptr) {
            return false;
        }
        else if (this->data > k) {
            return this->lchild->searchR(k);
        }
        else if (this->data < k) {
            return this->rchild->searchR(k);
        }
        else {
            return true;
        }
        return false;
    }
    Node* insertI(int k){
        Node* current_node = this;
        bool check = false;
        while (!check){
            if (current_node->data == k) {
                current_node->weight = current_node->weight + 1;
                return this;
            }
            else if (current_node->data > k) {
                if (current_node->lchild == nullptr) {
                    Node* createdNode = new Node(k);
                    current_node->lchild = createdNode;
                    return this;
                }
                else {
                    current_node = current_node->lchild;
                }
            }
            else if (current_node->data < k) {
                if (current_node->rchild == nullptr) {
                    Node* createdNode = new Node(k);
                    current_node->rchild = createdNode;
                    return this;
                }
                else {
                    current_node = current_node->rchild;
                }
            }
        }
        return this;
    }
    bool searchI(int k){
        Node* current_node = this;
        bool check = false;
        while (!check){
            if (current_node == nullptr) {
                return false;
            }
            else if (current_node->data > k) {
                
                current_node = current_node->lchild;
                
            }
            else if (current_node->data < k) {
                current_node = current_node->rchild;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
