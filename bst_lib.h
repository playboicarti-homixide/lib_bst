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
    void preOrder(){
        if (this == nullptr) {
            return;
        }
        std::cout << this->data << ", ";
        this->lchild->inOrder();
        this->rchild->inOrder();
    }
    void postOrder(){
        if (this == nullptr) {
            return;
        }
        this->lchild->inOrder();
        this->rchild->inOrder();
        std::cout << this->data << ", ";
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
    
    Node* deleteNode(int k){
        Node* parent_node = nullptr;
        Node* current_node = this;
        while (1){
            if (current_node->data > k) {
                parent_node = current_node;
                current_node = current_node->lchild;
                
            }
            else if (current_node->data < k) {
                parent_node = current_node;
                current_node = current_node->rchild;
            }
            else {
                if (current_node->lchild == nullptr && current_node->rchild == nullptr) {
                    delete current_node;
                    if (k < parent_node->data) {
                        parent_node->lchild = nullptr;
                        return this;
                    }
                    else{
                        parent_node->rchild = nullptr;
                        return this;
                    }
                }
                else{
                    if (k < parent_node->data) {
                        if (current_node->lchild != nullptr) {
                            parent_node->lchild = current_node->lchild;
                            delete current_node;
                            return this;
                        }
                        else {
                            parent_node->lchild = current_node->rchild;
                            delete current_node;
                            return this;
                        }
                    }
                    else{
                        if (current_node->rchild != nullptr) {
                            parent_node->rchild = current_node->rchild;
                            delete current_node;
                            return this;
                        }
                        else {
                            parent_node->rchild = current_node->lchild;
                            delete current_node;
                            return this;
                        }
                    }
                }
            }
        }
    }
    
    friend std::ostream &operator<<(std::ostream &os, const Node* n){
        os << "Node key--> " << n->data;
        if (n->lchild == nullptr)
        {
            os << "\nNode left-child key--> NULL";
        }
        else{
            os << "\nNode left-child key--> " << n->lchild->data;
        }
        if (n->rchild == nullptr)
        {
            os << "\nNode right-child key--> NULL";
        }
        else{
            os << "\nNode right-child key--> " << n->rchild->data;
        }
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Node* n){
        is >> n->data;
        n->lchild = nullptr;
        n->rchild = nullptr;
        return is;
    }
};
