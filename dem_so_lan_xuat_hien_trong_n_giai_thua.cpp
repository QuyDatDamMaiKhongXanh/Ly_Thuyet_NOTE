#include <bits/stdc++.h>
using namespace std;
int count1(int p, int n)
{
    int dem = 0;
    for (int i = p; i <= n; i += p)
    {
        int tam = i;
        while (tam % p == 0)
        {
            tam /= p;
            dem++;
        }
    }
    return dem;
}
int count2(int p, int n)
{
    int dem = 0;
    for (int i = p; i <= n; i *= p)
    {
        dem += n / i;
    }
    return dem;
}
int main()
{
    int p, n;
    cin >> p >> n;
    cout << count1(p, n) << " " << count2(p, n) << endl;
}