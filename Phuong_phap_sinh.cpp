#include <bits/stdc++.h>
using namespace std;
int a[1000001], ok = 1, cnt = 1, n, k;
void sinh_nhi_phan()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if (i == 0)
    {
        ok = 0;
        return;
    }
    else
    {
        a[i] = 1;
    }
}
void khoi_tao_nhi_phan()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}
void main_sinh_nhi_phan()
{
    cin >> n;
    khoi_tao_nhi_phan();
    while (ok == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh_nhi_phan();
    }
}
void khoi_tao_ckn()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}
void sinh_to_hop()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
        return;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
void main_sinh_to_hop()
{
    cin >> k >> n;
    khoi_tao_ckn();
    while (ok)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh_to_hop();
    }
}
void khoi_tao_sinh_hoan_vi()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}
void sinh_hoan_vi()
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
        return;
    }
    else
    {
        int j = n;
        while (a[j] < a[i])
        {
            j--;
        }
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
void main_sinh_hoan_vi()
{
    cin >> n;
    khoi_tao_sinh_hoan_vi();
    while (ok)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh_hoan_vi();
    }
}
void khoi_tao_sinh_phan_hoach()
{
    a[1] = n;
}
void sinh_phan_hoach()
{
    int i = cnt;
    while (i >= 1 && a[i] == 1)
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
        return;
    }
    else
    {
        a[i]--;
        int dem = cnt - i + 1;
        cnt = i;
        int h = dem / a[i];
        int r = dem % a[i];
        if (n)
        {
            for (int j = 1; j <= h; j++)
            {
                cnt++;
                a[cnt] = a[i];
            }
        }
        if (r)
        {
            cnt++;
            a[cnt] = r;
        }
    }
}
void main_sinh_phan_hoach()
{
    cin >> n;
    khoi_tao_sinh_phan_hoach();
    while (ok)
    {
        for (int i = 1; i <= cnt; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        sinh_phan_hoach();
    }
}
void dung_ham_sinh_hoan_vi()
{
    cin >> n;
    khoi_tao_sinh_hoan_vi();
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
    while (next_permutation(a + 1, a + n + 1))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    // neu la cau hinh cuoi sinh ra cau hinh dau
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
    cout << "Dung ham prev_permutation" << endl;
    for (int i = 1; i <= n; i++)
    {
        a[i] = n - i + 1;
    }
    while (prev_permutation(a + 1, a + n + 1))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    // neu la cau hinh dau thi no se thanh cau hinh cuoi
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
int main()
{
    // main_sinh_nhi_phan();
    // main_sinh_to_hop();
    // main_sinh_hoan_vi();
    // main_sinh_phan_hoach();
    dung_ham_sinh_hoan_vi();
}