// Develop branch

#include <iostream>
using namespace std;

struct node{
    int data;
    int weight = 1;
    node* rc;
    node* lc;
    node(int d){
        data = d;
        rc = nullptr;
        lc = nullptr;
    }
};

node* insert(node* r, int n){

    node* ne = new node(n);

    node* cur = r;
    node* fat = nullptr;
    if(r == NULL){
        return ne;
    }

    if(r->data == n){
        r->weight ++;
        return r;
    }

    while(cur != nullptr){
        fat = cur;
        if(cur->data < n){
            cur = cur->rc;
        }else{
            cur = cur->lc;
        }
    }

    if(fat->data < n){
        fat->rc = ne;
    }else{
        fat->lc = ne;
    }

    return r;
}

node *insert(node* r , int k){
    if(r == NULL){
        return new node(k);
    }

    if(r->data == k){
        return r;
    }

    if(r->data< k){
        r->rc = insert(r->rc, k);
    }else{
        r->lc = insert(r->lc , k);
    }

 return r;

}

int c = 0;

node* search(node *r , int n){
    node* cur = r;

    while(cur != nullptr){
        if(cur->data < n){
            cur = cur->rc;
        }else if(cur->data > n){
            cur = cur->lc;
        }else if(cur->data == n){
            c++;
            return cur;
        }
    }
    if(c != 0){
    }else {
    }
    return NULL;
}

node* src(node* r, int k){

    if(r == nullptr){
        return NULL;
    }

    if(r->data < k){
        return src(r->rc, k);
    }else if(r->data > k){
        return src(r->lc, k);
    }else if(r->data == k){
        return r;
    }

}

void pdr(node* a) {

if (a == nullptr) {
    return;
}    

cout << a->data << " "; 
pdr(a->lc); 
pdr(a->rc);

}

void inrd(node* b){

if(b == nullptr){
    return;
}
inrd(b->lc);
cout<< b->data <<" ";
inrd(b->rc);

}

void pstr(node* c){

if(c == nullptr){
    return;
}
pstr(c->lc);
pstr(c->rc);
cout<< c->data<<" ";

}

int max(int a ,int b){
    if(a> b){
        return a;
    }else{
        return b;
    }
}
int hg(node*r){
    if(r == nullptr){
        return 0;
    }
    int a = hg(r->lc);
    int b = hg(r->rc);

    return  max(a , b) + 1;
}

node* canc(node* r, int k){
    if(r== nullptr){
        return r;
    }

    if(k < r->data){
        r->lc = canc(r->lc, k);
    }else if(k > r->data){
        r->rc = canc(r->rc, k);
    }else if(r->data == k){
        if(r->rc == nullptr && r->lc == nullptr){
            delete r;
            return nullptr;
        }else if(r->rc != nullptr){
            node* cur = r->rc;
            delete r;
            return cur;
        }else if(r->lc != nullptr){
            node* cur = r->lc;
            delete r;
            return cur;
        }else if(r->rc != nullptr && r->lc != nullptr){

        node* min = r->rc;

        while (min->lc != nullptr) {
            min = min->lc; 
        }
        r->data = min->data;
        r->rc = canc(r->rc, min->data);

         return r;

        }else{
            cout<<"nodo non trovato"<<endl;
            return nullptr;
        }
    }
}

node* canc(node* r, int k) {
    node* fat = nullptr;
    node* cur = r;

    while (cur != nullptr && cur->data != k) {
        fat = cur;
        if (k < cur->data) {
            cur = cur->lc;
        } else {
            cur = cur->rc;
        }
    }

    if (cur == nullptr) {
        cout << "Nodo non trovato" << endl;
        return r;
    }

    if (cur->lc == nullptr) {
        if (fat == nullptr) {
            node* temp = cur->rc;
            delete cur;
            return temp;
        } else if (fat->lc == cur) {
            fat->lc = cur->rc;
        } else {
            fat->rc = cur->rc;
        }
    } else if (cur->rc == nullptr) {
        if (fat == nullptr) {
            node* temp = cur->lc;
            delete cur;
            return temp;
        } else if (fat->lc == cur) {
            fat->lc = cur->lc;
        } else {
            fat->rc = cur->lc;
        }
    } else {
        node* min = cur->rc;
        node* fatm = cur;
        while (min->lc != nullptr) {
            fatm = min;
            min = min->lc;
        }
        cur->data = min->data;
        if (fatm->lc == min) {
            fatm->lc = min->rc;
        } else {
            fatm->rc = min->rc;
        }
        delete min;
    }

    return r;
}
