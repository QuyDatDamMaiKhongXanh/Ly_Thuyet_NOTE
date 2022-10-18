#include <bits/stdc++.h>
using namespace std;
int prime[10000001] = {0};
void sieve()
{
    for (int i = 2; i <= 10000000; i++)
    {
        prime[i] = i;
    }
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (prime[i] == i)
        {
            for (int j = i * i; j <= 10000000; j += i)
            {
                if (prime[j] == j)
                {
                    prime[j] = i;
                }
            }
        }
    }
}
int main()
{
    // ex: liet ke cac uoc so nguyen to be nhat cua cac so tu 1->n
    sieve();
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cout << "prime[" << i << "]=" << prime[i] << endl;
    }
}