#include <iostream>
using namespace std;

void inmang(int a[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void vundong(int a[], int n, int size, int i)
{
    int maxidx = i;
    int trai = 2 * i;
    int phai = 2 * i + 1;

    if(trai <= size && a[trai] > a[maxidx])
    {
        maxidx = trai;
    }

    if(phai <= size && a[phai] > a[maxidx])
    {
        maxidx = phai;
    }

    if(maxidx != i)
    {
        int tam = a[i];
        a[i] = a[maxidx];
        a[maxidx] = tam;

        cout << "trang thai sau khi doi: ";
        inmang(a, n);

        vundong(a, n, size, maxidx);
    }
}

void sapxepvundong(int a[], int n)
{
    cout << "\ncac buoc tao max heap\n";
    for(int i = n / 2; i >= 1; i--)
    {
        cout << "\nvun dong tai node " << i << endl;

        vundong(a, n, n, i);

        cout << "trang thai hien tai: ";
        inmang(a, n);
    }

    cout << "\nmax heap thu duoc:\n";
    inmang(a, n);

    cout << "\ncac buoc sap xep\n";
    for(int i = n; i >= 2; i--)
    {
        int tam = a[1];
        a[1] = a[i];
        a[i] = tam;

        cout << "\ndoi root voi phan tu cuoi:\n";
        inmang(a, n);

        vundong(a, n, i - 1, 1);

        cout << "trang thai sau khi vun lai:\n";
        inmang(a, n);
    }
}

int main()
{
    int n;
    cout << "nhap so phan tu n: ";
    cin >> n;

    int mang[100];
    cout << "nhap cac phan tu cua mang:\n";
    for(int i = 1; i <= n; i++)
    {
        cin >> mang[i];
    }

    cout << "\ntrang thai ban dau:\n";
    inmang(mang, n);

    sapxepvundong(mang, n);

    cout << "\nket qua cuoi:\n";
    inmang(mang, n);

    return 0;
}