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
    ll a[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll tam[n][m];
    memset(tam, 0, sizeof(tam));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i == 0)
                tam[i][j] = a[i][j];
            else
            {
                if (a[i][j])
                {
                    tam[i][j] = a[i][j] + tam[i - 1][j];
                }
                else
                    tam[i][j] = 0;
            }
        }
    }
    cout << endl;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << tam[i][j] << " ";
        }
        cout << endl;
    }
    ll res = -1e9;
    for (ll i = 0; i < n; i++)
    {
        res = max(res, max_area(tam[i]));
    }
    cout << "res=" << res << endl;
}
