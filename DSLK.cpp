#include<iostream>
#include<string>
using namespace std;

struct Ngay{ 
    int ngay, thang, nam; 
};
struct SinhVien {
    string maSV, hoTen, diaChi, lop, khoa;
    int gioiTinh;
    Ngay ngaySinh;
};
struct Node {
    SinhVien data;
    Node *link;
};
struct List { Node *first, *last; };

void Init(List &l){ 
    l.first = l.last = NULL; 
}
Node* CreateNode(SinhVien x) {
    Node *p = new Node;
    if (!p) return NULL;
    p->data = x; p->link = NULL;
    return p;
}

void NhapSV(SinhVien &sv) {
    cout << "Ma SV: "; 
    cin >> sv.maSV; 
    cin.ignore();
    cout << "Ho Ten: "; 
    getline(cin, sv.hoTen);
    cout << "GT (0-Nam, 1-Nu): "; 
    cin >> sv.gioiTinh;
    cout << "Ngay thang nam sinh: "; 
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
    cin.ignore(); 
    cout << "Dia chi: "; 
    getline(cin, sv.diaChi);
    cout << "Lop: "; 
    getline(cin, sv.lop);
    cout << "Khoa: "; 
    getline(cin, sv.khoa);
}

void AddLast(List &l, Node *p) {
    if (!p) return;
    if (!l.first) l.first = l.last = p;
    else { l.last->link = p; l.last = p; }
}
void DoiCho(SinhVien &a, SinhVien &b){ 
    SinhVien t = a; a = b; b = t; 
}

void Sapxep(List &l) {
    for (Node *p1 = l.first; p1; p1 = p1->link)
        for (Node *p2 = p1->link; p2; p2 = p2->link)
            if (p1->data.maSV > p2->data.maSV) DoiCho(p1->data, p2->data);
}

void ChenGiuThuTu(List &l, Node *p) 
{
    if (!p) return;
    if (!l.first || p->data.maSV < l.first->data.maSV) {
        p->link = l.first; l.first = p;
        if (!l.last) l.last = p; return;
    }
    Node *c = l.first;
    while (c->link && c->link->data.maSV < p->data.maSV) c = c->link;
    p->link = c->link; c->link = p;
    if (!p->link) l.last = p;
}

void In(List l) {
    cout << "\nMa SV\t| Ho Ten\t\t| Lop\t| Ngay sinh" << endl;
    for (Node *p = l.first; p; p = p->link)
        cout << p->data.maSV << "\t| " << p->data.hoTen << "\t| " << p->data.lop << "\t| " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
}

int main() {
    List l; Init(l);
    int n; cout << "Nhap n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "SV " << i + 1 << endl;
        SinhVien x; NhapSV(x); AddLast(l, CreateNode(x));
    }
    Sapxep(l);
    cout << "\nDS sau xep:"; In(l);

    cout << "\nChen SV moi:\n";
    SinhVien svMoi; NhapSV(svMoi);
    ChenGiuThuTu(l, CreateNode(svMoi));
    cout << "\nKet qua cuoi:"; In(l);
    system("pause");
    return 0;
}