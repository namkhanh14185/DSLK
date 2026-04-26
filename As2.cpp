#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node *link;
};

struct List 
{
    Node *first;
    Node *last;
};

void Init(List &l) 
{ 
    l.first = l.last = NULL; 
}

Node*CreateNode(int x) 
{
    Node*p=new Node;
    if (!p) return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}

void AddLast(List &l, Node *p) 
{
    if (!p) return;
    if (!l.first) {
        l.first = l.last = p;
    } else {
        l.last->link = p;
        l.last = p;
    }
    l.last->link = l.first;
}
void NhapDuLieu(int &n, int &m) {
    do {
        cout << "Nhap so nguoi choi (N > 0): ";
        cin >> n;
        if (n <= 0) cout << "Loi: N phai lon hon 0!\n";
    } while (n <= 0);

    do {
        cout << "Nhap buoc nhay (M >= 0): ";
        cin >> m;
        if (m < 0) cout << "Loi: M khong duoc am!\n";
    } while (m < 0);
}
void Josephus(int n, int m) 
{
    List l; 
    Init(l);
    for (int i = 1; i <= n; i++) AddLast(l, CreateNode(i));
    Node* p = l.first;
    Node* prev = l.last;
    cout<<"\n--- KET QUA LOAI ---" << endl;
    cout<<"Buoc\tNguoi bi loai" << endl;

    int dem=0;
    while(p->link != p) 
    { 
        for(int i = 0; i < m; i++) 
        {
            prev = p;
            p = p->link;
        }
        dem++;
        cout<<dem<<"\tNguoi so "<<p->data<< endl;
        prev->link=p->link;
        delete p;
        p=prev->link;
    }
    cout<<"--------------------"<< endl;
    cout<<"\n=> NGUOI CHIEN THANG: "<<p->data << endl;
    delete p;
}

int main() 
{
    int n, m;
    NhapDuLieu(n, m);
    Josephus(n, m);
    cout<<"\nNhan Enter de ket thuc...";
    cin.ignore(); 
    cin.get();
    return 0;
}