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

void vundong(int a[], int n, int i)
{
    int maxidx = i;
    int trai = 2 * i;
    int phai = 2 * i + 1;

    if(trai <= n && a[trai] > a[maxidx])
    {
        maxidx = trai;
    }

    if(phai <= n && a[phai] > a[maxidx])
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

        vundong(a, n, maxidx);
    }
}

void sapxepvundong(int a[], int n)
{
    cout << "\ncac buoc tao max heap\n";
    for(int i = n / 2; i >= 1; i--)
    {
        cout << "\nvun dong tai node " << i << endl;

        vundong(a, n, i);

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

        vundong(a, i - 1, 1);

        cout << "trang thai sau khi vun lai:\n";
        inmang(a, n);
    }
}

int main()
{
    int mang1[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n1 = 10;

    cout << "\ncay 1\n";
    cout << "trang thai ban dau:\n";
    inmang(mang1, n1);

    sapxepvundong(mang1, n1);

    cout << "\nket qua cuoi:\n";
    inmang(mang1, n1);

    int mang2[] = {0, 11, 54, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};
    int n2 = 12;

    cout << "\n-------------------------------------\n";
    cout << "\ncay 2\n";
    cout << "trang thai ban dau:\n";
    inmang(mang2, n2);

    sapxepvundong(mang2, n2);
    
    cout << "\nket qua cuoi:\n";
    inmang(mang2, n2);
    return 0;
}