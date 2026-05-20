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

void duyetTienTo(PNode P) {
    if (P != NULL) {
        cout << P->info << " ";
        duyetTienTo(P->left);
        duyetTienTo(P->right);
    }
}

void duyetHauTo(PNode P) {
    if (P != NULL) {
        duyetHauTo(P->left);
        duyetHauTo(P->right);
        cout << P->info << " ";
    }
}

void duyetTrungTo(PNode P) {
    if (P != NULL) {
        if (P->left != NULL && P->right != NULL) cout << "( ";
        duyetTrungTo(P->left);
        cout << P->info << " ";
        duyetTrungTo(P->right);
        if (P->left != NULL && P->right != NULL) cout << ") ";
    }
}

int demSoNut(PNode P) {
    if (P == NULL) return 0;
    return 1 + demSoNut(P->left) + demSoNut(P->right);
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
    
    cout << "Tien to: ";
    duyetTienTo(root);
    
    cout << "\nHau to: ";
    duyetHauTo(root);
    
    cout << "\nTrung to: ";
    duyetTrungTo(root);
    
    cout << "\nTong so nut: " << demSoNut(root);
    cout << endl;
    
    return 0;
}