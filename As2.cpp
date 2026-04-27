#include<iostream>
#include<ctime>
using namespace std;
struct Node 
{
    int data;
    Node* link;
};

struct List 
{
    Node* first;
    Node* last;
};

void Init(List &l) 
{
    l.first = l.last = NULL;
}

Node* CreateNode(int x) 
{
    Node* p = new Node;
    if(!p) return NULL;
    p->data= x;
    p->link= NULL;
    return p;
}

void AddLast(List &l, Node*p) 
{
    if(!p) return;
    if(!l.first) 
    {
        l.first = l.last = p;
    } 
    else 
    {
        l.last->link = p;
        l.last = p;
    }
    l.last->link = l.first;
}

void Josephus(int n, int m) 
{
    clock_t start = clock();

    List l; 
    Init(l);
    for (int i = 1; i <= n; i++) {
        AddLast(l, CreateNode(i));
    }

    Node* p = l.first;
    Node* prev = l.last;
    if (n <= 100) cout<<"Thu tu bi loai: ";

    while (p->link != p) 
    {
        for (int i = 0; i < m; i++) 
        {
            prev = p;
            p = p->link;
        }
        if (n <= 100) cout<<p->data<<" ";
        
        prev->link = p->link;
        delete p;
        p = prev->link;
    }
    clock_t end = clock();
    double duration = (double)(end - start);

    cout << "\n=> NGUOI CHIEN THANG: " << p->data << endl;
    cout << "==> Thoi gian chay (N=" << n << "): " << duration << " giay" << endl;
    
    delete p;
}

int main() {
    int n, m;
    cout<<"Nhap N (so nguoi): "; 
    cin>>n;
    cout<<"Nhap M (buoc nhay): "; 
    cin>>m;
    Josephus(n, m);
    cout<<"\nNhan Enter de thoat...";
    cin.ignore();
    cin.get();
    
    return 0;
}