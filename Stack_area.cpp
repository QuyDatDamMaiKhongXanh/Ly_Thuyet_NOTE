#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll a[1000001], n;
ll max_area()
{
    stack<ll> st;
    ll i = 0;
    ll res = 0;
    while (i < n)
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
                res = max(res, i * a[top]);
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
            res = max(res, i * a[top]);
        }
        else
        {
            res = max(res, a[top] * (i - st.top() - 1));
        }
    }
    return res;
}
// bonus them insert_sort
void insert_sort(ll a[], ll n)
{
    ll pos;
    for (ll i = 1; i < n; i++)
    {
        ll x = a[i];
        for (pos = i; pos >= 0 && x < a[pos - 1];)
        {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;
    }
}
int main()
{
    faster();
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << max_area() << endl;
    insert_sort(a, n);
    cout << "Mang sau khi sap xep la:" << endl;
    for (ll i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}