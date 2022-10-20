#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[93] = {0};
void init()
{
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 92; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}
char xau_fibo(int n, int k)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (k <= f[n - 2])
        return xau_fibo(n - 2, k);
    else
        return xau_fibo(n - 1, k - f[n - 2]);
}
void main_xau_fibo()
{
    init();
    int n, k;
    cin >> n >> k;
    cout << xau_fibo(n, k);
}
/*
// [1 1] ^ n -> [fn+1 fn]
// [1 0]        [fn fn-1]
*/
struct matrix
{
    int n;
    ll a[101][101];
    matrix operator*(matrix khac)
    {
        matrix res;
        res.n = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    res.a[i][j] += a[i][k] * khac.a[k][j];
                    res.a[i][j] %= (int)1000000007;
                }
            }
        }
        return res;
    }
};
matrix pow_mod(matrix a, int k)
{
    matrix res;
    res.n = a.n;
    for (int i = 0; i < res.n; i++)
    {
        for (int j = 0; j < res.n; j++)
        {
            if (i == j)
                res.a[i][j] = 1;
            else
                res.a[i][j] = 0;
        }
    }
    while (k)
    {
        if (k & 1)
        {
            res = res * a;
        }
        a = a * a;
        k = k >> 1;
    }
    return res;
}
void main_luy_ma_tran()
{
    int n, k;
    cin >> n >> k;
    matrix a;
    a.n = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a.a[i][j];
        }
    }
    matrix res = pow_mod(a, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    main_luy_ma_tran();
}