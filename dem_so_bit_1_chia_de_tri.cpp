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
vector<ll> v;
void init(ll n)
{
    ll tam = log2(n);
    for (ll i = 1; i <= tam; i++)
    {
        v.push_back((ll)(pow(2, i)));
    }
}
ll find_pos(ll pos, ll n, ll idex)
{
    if (pos % 2 == 1)
        return 1;
    if (pos == v[idex])
        return n % 2;
    if (pos < v[idex])
    {
        return find_pos(pos, n / 2, idex - 1);
    }
    else
    {
        return find_pos(2 * v[idex] - pos, n / 2, idex - 1);
    }
}
int main()
{
    faster();
    ll n, l, r;
    cin >> n >> l >> r;
    init(n);
    ll idex = v.size() - 1;
    ll cnt = 0;
    for (ll i = l; i <= r; i++)
    {
        if (find_pos(i, n, idex))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}