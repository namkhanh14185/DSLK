#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

void heapify(vector<int>& arr, int n, int i, int& step) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        cout << "   -> Buoc nho " << step++ << ": ";
        printArray(arr);
        heapify(arr, n, largest, step);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    cout << "--- XAY DUNG MAX-HEAP ---\n";
    for (int i = n / 2 - 1; i >= 0; i--) {
        int subStep = 1;
        heapify(arr, n, i, subStep);
    }
    cout << "--- SAP XEP ---\n";
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        int subStep = 1;
        heapify(arr, i, 0, subStep);
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    heapSort(arr);
    return 0;
}