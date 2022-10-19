#include <bits/stdc++.h>
using namespace std;
int mod = (int)1e6;
// tinh ckn
// cach 1 tinh theo cong thuc
int tohop(int k, int n)
{
    int res = 1;
    for (int i = 1; i <= k; i++)
    {
        res *= (n - i + 1);
        res /= i;
        res %= mod;
    }
    return res;
}
// cach 2 quy hoach dong dung cho input <=1e7
int tohop1[1001][1001] = {0};
void init()
{
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (j == 0 || i == j)
            {
                tohop1[i][j] = 1;
            }
            else
                tohop1[i][j] = tohop1[i - 1][j] + tohop1[i - 1][j - 1];
        }
    }
}
// de qui
int tohop2(int k, int n)
{
    if (k == 0 || n == k)
        return 1;
    return tohop2(k, n - 1) + tohop2(k - 1, n - 1);
}
// luy thua nhi phan
int pow1(int a, int b, int c)
{
    int res = 1;
    a %= c;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
            res %= c;
        }
        a *= a;
        a %= c;
        b = b >> 1;
    }
    return res;
}
int pow2(int a, int b, int c)
{
    if (b == 0)
        return 1;
    int tam = pow2(a, b / 2, c);
    if (b & 1)
        return (tam % c) * (tam % c) % c * (a % c) % c;
    else
        return (tam % c) * (tam % c) % c;
}
int main()
{
    init();
    cout << tohop(2, 8) << " " << tohop1[8][2] << " " << tohop2(2, 8) << endl;
    cout << pow1(2, 4, mod) << " " << pow2(2, 4, mod) << endl;
}