#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int prime[10000001] = {0}, l, r;
void sieve()
{
    fill(prime, prime + 10000001, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < (int)sqrt(10000000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 10000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
void sieve2()
{
    // sang so nguyen to tren doan
    int prime2[r - l + 1];
    fill(prime2, prime2 + r - l + 1, 1);
    for (int i = 2; i <= sqrt(r); i++)
    {
        for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
        {
            prime2[j - l] = 0;
        }
    }
    for (int i = max(l, 2); i <= r; i++)
    {
        if (prime2[i - l])
        {
            cout << i << endl;
        }
    }
}
int main()
{
    cin >> l >> r;
    // sieve2();
    sieve();
    cout << "Sang 1" << endl;
    for (int i = l; i <= r; i++)
    {
        if (prime[i])
        {
            cout << i << endl;
        }
    }
}
