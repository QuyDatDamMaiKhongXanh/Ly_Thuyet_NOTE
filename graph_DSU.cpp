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

ll n, m, parent[1001], sz[1001];
vector<ll> adj[1001];
void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        sz[i] = 1;
        parent[i] = i;
    }
}
ll find(int u)
{
    if (parent[u] == u)
        return u;
    else
        return parent[u] = find(parent[u]);
}
bool uni(ll x, ll y)
{
    int x = find(x);
    int y = find(y);
    if (x == y)
    {
        return false;
    }
    else
    {
        if (sz[x] < sz[y])
        {
            parent[x] = y;
            sz[y] += sz[x];
            return true;
        }
        else
        {
            parent[y] = x;
            sz[x] += sz[y];
            return true;
        }
    }
}
int main()
{
    faster();
}
