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
};
