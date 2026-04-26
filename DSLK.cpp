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

int main() {
    List listSV;
    Init(listSV);
    
    cout << "Da khoi tao danh sach sinh vien (C++ version) thanh cong!" << endl;
    return 0;
}