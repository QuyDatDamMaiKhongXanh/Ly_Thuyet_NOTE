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
ll n, m, d[1001];
vector<pair<ll, ll>> adj[1001];
void init()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
    }
}
void dijkstra(ll s)
{
    for (ll i = 1; i <= n; i++)
    {
        d[i] = 1e9;
    }
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qe;
    qe.push({0, s});
    while (!qe.empty())
    {
        auto u = qe.top();
        qe.pop();
        ll kc = u.first;
        ll dinh = u.second;
        if (kc > d[dinh])
            continue;
        for (auto x : adj[dinh])
        {
            ll v = x.first;
            if (d[v] > d[dinh] + x.second)
            {
                d[v] = d[dinh] + x.second;
                qe.push({d[v], x.first});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
int main()
{
    faster();
    init();
    dijkstra(1);
    return 0;
}
