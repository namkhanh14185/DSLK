#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    string info;
    Node* left;
    Node* right;
};
typedef Node* PNode;

PNode taoNut(string x) 
{
    PNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

bool laToanTu(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int doUuTien(char c) 
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string chuyenTrungToSangHauTo(string trungTo) 
{
    string hauTo = "";
    char stack[100];
    int top = -1;

    for (int i = 0; i < trungTo.length(); i++) 
    {
        char c = trungTo[i];
        if (c == ' ') continue;

        if (!laToanTu(c) && c != '(' && c != ')') 
        {
            hauTo += c;
        } 
        else if (c == '(') 
        {
            top++;
            stack[top] = c;
        } 
        else if (c == ')') 
        {
            while (top != -1 && stack[top] != '(') 
            {
                hauTo += stack[top];
                top--;
            }
            if (top != -1) top--;
        } 
        else if (laToanTu(c)) 
        {
            while (top != -1 && doUuTien(stack[top]) >= doUuTien(c)) 
            {
                hauTo += stack[top];
                top--;
            }
            top++;
            stack[top] = c;
        }
    }

    while (top != -1) 
    {
        hauTo += stack[top];
        top--;
    }
    return hauTo;
}

PNode dungCayTuHauTo(string hauTo) 
{
    PNode stack[100];
    int top = -1;
    
    for (int i = 0; i < hauTo.length(); i++) 
    {
        string s = "";
        s += hauTo[i];
        PNode t = taoNut(s);
        
        if (!laToanTu(hauTo[i])) 
        {
            top++;
            stack[top] = t;
        } 
        else 
        {
            t->right = stack[top];
            top--;
            
            t->left = stack[top];
            top--;
            
            top++;
            stack[top] = t;
        }
    }
    return stack[top];
}

void duyetTienTo(PNode P) 
{
    if (P != NULL) 
    {
        cout << P->info << " ";
        duyetTienTo(P->left);
        duyetTienTo(P->right);
    }
}

void duyetHauTo(PNode P) 
{
    if (P != NULL) 
    {
        duyetHauTo(P->left);
        duyetHauTo(P->right);
        cout << P->info << " ";
    }
}

void duyetTrungTo(PNode P) 
{
    if (P != NULL) 
    {
        if (P->left != NULL && P->right != NULL) cout << "( ";
        duyetTrungTo(P->left);
        cout << P->info << " ";
        duyetTrungTo(P->right);
        if (P->left != NULL && P->right != NULL) cout << ") ";
    }
}

int demSoNut(PNode P) 
{
    if (P == NULL) return 0;
    return 1 + demSoNut(P->left) + demSoNut(P->right);
}

int main() 
{
    string trungTo;
    cout << "Nhap bieu thuc: ";
    getline(cin, trungTo); 
    
    string hauTo = chuyenTrungToSangHauTo(trungTo);
    PNode root = dungCayTuHauTo(hauTo);
    
    cout << "\nDUYET CAY" << endl;
    cout << "Tien to : ";
    duyetTienTo(root);
    
    cout << "\nHau to  : ";
    duyetHauTo(root);
    
    cout << "\nTrung to: ";
    duyetTrungTo(root);
    
    cout << "\nTong so nut: " << demSoNut(root);
    cout << endl;
    
    return 0;
}