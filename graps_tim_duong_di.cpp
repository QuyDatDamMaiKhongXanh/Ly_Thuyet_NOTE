#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
using namespace std;
bool visited[1000001] = {0};
ll n, m, s, t, parent[1000001] = {0};
vector<ll> adj[1000001];
// tim duong di tu dinh s den dinh t
// de bai: trong qua trinh mo rong uu tien mo rong cac dinh nho hon
void dfs(ll i)
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (!visited[x])
        {
            parent[x] = i;
            dfs(x);
        }
    }
}

void init()
{
    cin >> n >> m >> s >> t;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
}
void slove()
{
    init();
    dfs(s);
    if (visited[t])
    {
        vector<ll> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    slove();
}
