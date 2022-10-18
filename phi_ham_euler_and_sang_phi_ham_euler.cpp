// khai niem phi ham euler:la so cac so nho hon n cos uoc chung lon nhat cua no voi n bang 1
#include <bits/stdc++.h>
using namespace std;
int euler[10000001] = {0};
// cach 1 tim cong euler bang cong thuc
// phi=n*(1-p)*(1-p2)... voi p la thua so nguyen to cua n
int euler1(int n)
{
    int res = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n != 1)
    {
        res -= res / n;
    }
    return res;
}
void sieve() // sang
{
    for (int i = 2; i <= 10000000; i++)
    {
        euler[i] = i;
    }
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (euler[i] == i)
        {
            euler[i] = i - 1;
            for (int j = 2 * i; j <= 10000000; j += i)
            {
                euler[j] -= euler[j] / i;
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    cin >> n;
    cout << euler1(n) << " " << euler[n] << endl;
}