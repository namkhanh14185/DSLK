#include <iostream>
#include <string>
using namespace std;

struct Node {
    string info;
    Node* left;
    Node* right;
};
typedef Node* PNode;

PNode taoNut(string x) {
    PNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main() {
    PNode root = taoNut("-");
    PNode chia = taoNut("/");
    PNode mu = taoNut("^");
    
    root->left = chia;
    root->right = mu;
    
    cout << "Nut goc: " << root->info << endl;
    cout << "Con trai: " << root->left->info << " , Con phai: " << root->right->info << endl;
    
    return 0;
}