#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, S;
    cin >> n >> S;
    int a[n];
    ll res[S + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    res[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (j >= a[i])
            {
                res[j] += res[j - a[i]];
            }
        }
    }
    cout << res[S] << endl;
}