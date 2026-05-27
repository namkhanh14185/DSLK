#include <iostream>
using namespace std;

void inMang(int a[], int n) {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void vundong(int a[], int n, int i) {
    int max = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= n && a[left] > a[max]) max = left;
    if(right <= n && a[right] > a[max]) max = right;
    if(max != i) {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        cout << "Trang thai sau khi doi: ";
        inMang(a, n);
        vundong(a, n, max);
    }
}

void heapSort(int a[], int n) {
    cout << "\nCac buoc tao max heap\n";
    for(int i = n / 2; i >= 1; i--) {
        cout << "\nVun dong tai node " << i << endl;
        vundong(a, n, i);
        cout << "Trang thai hien tai: ";
        inMang(a, n);
    }
    cout << "\nCac buoc sap xep\n";
    for(int i = n; i >= 2; i--) {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        cout << "\nDoi root voi phan tu cuoi:\n";
        inMang(a, n);
        vundong(a, i - 1, 1);
        cout << "Trang thai sau khi vun lai:\n";
        inMang(a, n);
    }
}

int main() {
    int a[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n1 = 10;
    heapSort(a, n1);
    return 0;
}