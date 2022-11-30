#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Forb(i, a, b) for (int i = a; i <= b; i++)
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define is insert
#define pi pair<int, int>
#define vii vector<pi>
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n, m;
ll max_area(ll a[])
{
    ll i = 0;
    ll res = -1e9;
    stack<ll> st;
    while (i < m)
    {
        if (st.empty() || a[i] >= a[st.top()])
        {
            st.push(i++);
        }
        else
        {
            ll top = st.top();
            st.pop();
            if (st.empty())
            {
                res = max(res, a[top] * i);
            }
            else
            {
                res = max(res, a[top] * (i - st.top() - 1));
            }
        }
    }
    while (!st.empty())
    {
        ll top = st.top();
        st.pop();
        if (st.empty())
        {
            res = max(res, a[top] * i);
        }
        else
        {
            res = max(res, a[top] * (i - st.top() - 1));
        }
    }
    return res;
}
int main()
{
    faster();
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    cin >> n >> m;
    ll a[n + 1][m + 1];
    memset(a, 0, sizeof(a));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll chinh[n + 1][m + 1];
    memset(chinh, 0, sizeof(chinh));
    ll phu[n + 1][m + 1];
    memset(phu, 0, sizeof(phu));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                chinh[i][j] = a[i][j];
            }
            else
            {
                chinh[i][j] = a[i][j] + chinh[i - 1][j - 1];
            }
            if (i == 1 && j == n)
            {
                phu[i][j] = a[i][j];
            }
            else
            {
                phu[i][j] = a[i][j] + phu[i - 1][j + 1];
            }
        }
    }
    ll ans = -1e9;
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = n; j >= 1; j--)
        {
            ll tam = min(i, j);
            ll hang = i - tam;
            ll cot = j - tam;
            for (int k = 0; k < tam; k++)
            {
                ans = max(ans, chinh[i][j] - chinh[hang + k][cot + k] - (phu[i][cot + k + 1] - phu[hang + k][j + 1]));
            }
        }
    }
    cout << ans << endl;
}
// 4 4
// 9 -2 8 0
// -6 -2 0 -9
// 4 -5 6 1
// 1 3 4 9
//  output = 26