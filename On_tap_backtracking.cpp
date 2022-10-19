#include <bits/stdc++.h>
using namespace std;
int a[1000001] = {0}, n, k;
bool check[100001] = {0};
void sinh_nhi_phan(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[j];
            }
            cout << endl;
        }
        else
            sinh_nhi_phan(i + 1);
    }
}
void main_sinh_nhi_phan()
{
    cin >> n;
    sinh_nhi_phan(1);
}
void sinh_ckn(int i)
{
    for (int j = a[i - 1] + 1; j <= n; j++)
    {
        a[i] = j;
        if (i == k)
        {
            for (int h = 1; h <= k; h++)
            {
                cout << a[h];
            }
            cout << endl;
        }
        else
            sinh_ckn(i + 1);
    }
}
void main_sinh_ckn()
{
    cin >> k >> n;
    a[0] = 0;
    sinh_ckn(1);
}
void sinh_hoan_vi(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!check[j])
        {
            check[j] = true;
            a[i] = j;
            if (i == n)
            {
                for (int h = 1; h <= n; h++)
                {
                    cout << a[h];
                }
                cout << endl;
            }
            else
                sinh_hoan_vi(i + 1);
            check[j] = false;
        }
    }
}
void main_sinh_hoan_vi()
{
    cin >> n;
    sinh_hoan_vi(1);
}
int main()
{
    main_sinh_hoan_vi();
}