#include <iostream>
#include <string>
using namespace std;
struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    string maSV;
    string hoTen;
    int gioiTinh; 
    Ngay ngaySinh;
    string diaChi;
    string lop;
    string khoa;
};

struct Node {
    SinhVien data;
    Node *link;
};

struct List {
    Node *first;
    Node *last;
};

void Init(List &l) {
    l.first = l.last = NULL;
}

Node* CreateNode(SinhVien x) {
    Node *p = new Node;
    if (p == NULL) return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}
void NhapSV(SinhVien &sv) {
    cout<< "Nhap Ma SV: "; 
    cin>>sv.maSV;
    cin.ignore(); 
    cout<< "Nhap Ho Ten: "; 
    getline(cin, sv.hoTen);
    cout<< "Gioi tinh (0: Nam, 1: Nu): "; 
    cin>>sv.gioiTinh;
    cout<< "Nhap Ngay, Thang, Nam sinh: "; 
    cin>>sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
    cin.ignore();
    cout << "Nhap Dia chi: "; 
    getline(cin, sv.diaChi);
    cout << "Nhap Lop: "; 
    getline(cin, sv.lop);
    cout << "Nhap Khoa: "; 
    getline(cin, sv.khoa);
}
void AddLast(List &l, Node *p) {
    if (p == NULL) return;
    if (l.first == NULL) 
    {
        l.first=l.last=p;
    } 
    else 
    {
        l.last->link=p;
        l.last=p;
    }
}
void DoiCho(SinhVien &a, SinhVien &b) 
{
    SinhVien tmp = a; 
    a = b; 
    b = tmp;
}

void Sapxep(List &l) 
{
    if (l.first == NULL) return;
    for (Node *p1 = l.first; p1 != NULL; p1 = p1->link) {
        for (Node *p2 = p1->link; p2 != NULL; p2 = p2->link) {
            if (p1->data.maSV > p2->data.maSV) {
                DoiCho(p1->data, p2->data);
            }
        }
    }
}

void In(List l) {
    cout << "\nMa SV\t| Ho Ten\t\t| Lop\t| Ngay sinh" << endl;
    Node *p=l.first;
    while(p!= NULL) {
        cout << p->data.maSV << "\t| " << p->data.hoTen << "\t| " << p->data.lop << "\t| " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
        p = p->link;
    }
}

int main() {
    List l; Init(l);
    int n; cout << "Nhap n: "; cin >> n;
    for(int i=0; i<n; i++) {
        cout << "SV " << i+1 << endl;
        SinhVien x; NhapSV(x);
        AddLast(l, CreateNode(x));
    }

    cout << "\nTruoc khi xep:"; In(l);
    Sapxep(l);
    cout << "\nSau khi xep:"; In(l);
    return 0;
}