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
    PNode cong = taoNut("+");
    PNode nhan1 = taoNut("*");
    PNode a = taoNut("a");
    PNode b = taoNut("b");
    PNode c = taoNut("c");
    PNode d = taoNut("d");
    
    root->left = chia;
    chia->left = cong; chia->right = d;
    cong->left = nhan1; cong->right = c;
    nhan1->left = a; nhan1->right = b;
    
    PNode mu = taoNut("^");
    PNode tru = taoNut("-");
    PNode nhan2 = taoNut("*");
    PNode e = taoNut("e");
    PNode f = taoNut("f");
    PNode h = taoNut("h");
    PNode g = taoNut("g");
    
    root->right = mu;
    mu->left = tru; mu->right = g;
    tru->left = nhan2; tru->right = h;
    nhan2->left = e; nhan2->right = f;
    
    cout << "Cay bieu thuc da duoc dung xong." << endl;
    
    return 0;
}