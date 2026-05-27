#include <iostream>
using namespace std;

void inMang(int a[], int n) {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void vundongSuaLoi(int a[], int n, int size, int i) {
    int max = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= size && a[left] > a[max]) max = left;
    if(right <= size && a[right] > a[max]) max = right;
    if(max != i) {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        cout << "Trang thai sau khi doi: ";
        inMang(a, n); 
        vundongSuaLoi(a, n, size, max);
    }
}

void heapSort(int a[], int n) {
    for(int i = n / 2; i >= 1; i--) vundongSuaLoi(a, n, n, i);
    for(int i = n; i >= 2; i--) {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        vundongSuaLoi(a, n, i - 1, 1);
    }
}

int main() {
    int a[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n1 = 10;
    heapSort(a, n1);
    return 0;
}