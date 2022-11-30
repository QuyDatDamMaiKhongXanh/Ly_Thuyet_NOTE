#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
using namespace std;
bool visited[1000001] = {0};
ll n, m;
vector<ll> adj[1000001];
void dfs(ll i)
{
    visited[i] = true;
    cout << i << " ";
    for (auto x : adj[i])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}
void bfs(ll i)
{
    queue<ll> qe;
    qe.push(i);
    visited[i] = true;
    while (!qe.empty())
    {
        ll top = qe.front();
        qe.pop();
        cout << top << " ";
        for (auto x : adj[top])
        {
            if (!visited[x])
            {
                qe.push(x);
                visited[x] = true;
            }
        }
    }
    cout << endl;
}
void init()
{
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
    init();
    dfs(1);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    bfs(1);
}
