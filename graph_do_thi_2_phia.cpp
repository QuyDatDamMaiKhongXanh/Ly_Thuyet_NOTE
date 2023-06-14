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
ll n, m;
bool color[1001], parent[1001];
vector<ll> adj[1001];
bool dfs(ll i)
{
    color[i] = 3 - color[parent[i]];
    for (auto x : adj[i])
    {
        if (!color[x])
        {
            if (!dfs(x))
                return false;
        }
        else if (color[x] == color[i])
        {
            return false;
        }
    }
    return true;
}
void init()
{
    color[0] = 1;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
int main()
{
    faster();
    // nho xet tat ca cac dinh
}
