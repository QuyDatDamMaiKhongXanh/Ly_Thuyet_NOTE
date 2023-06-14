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
struct edge
{
    ll x, y, w;
};
ll n, m;
bool visited[1001];
vector<pair<ll, ll>> adj[1001];
void init()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}
void prim()
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qe;
    qe.push({0, 1});
    ll cnt = 0;
    ll sum = 0;
    while (!qe.empty())
    {
        auto p = qe.top();
        qe.pop();
        if (visited[p.second] == true)
            continue;
        sum += p.first;
        cnt++;
        visited[p.second] = true;
        for (auto x : adj[p.second])
        {
            if (!visited[x.first])
            {
                qe.push({x.second, x.first});
            }
        }
    }
    cout << sum << endl;
}
int main()
{
    faster();
    init();
    prim();
    return 0;
}
