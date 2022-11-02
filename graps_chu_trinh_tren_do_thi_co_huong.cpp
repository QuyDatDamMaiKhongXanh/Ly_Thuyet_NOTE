#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll color[1001], n, m;
vector<ll> adj[1001];
void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}
bool dfs(int i)
{
    color[i] = 1;
    for (auto x : adj[i])
    {
        if (!color[x])
        {
            if (dfs(x))
                return true;
        }
        else if (color[x] == 1)
            return true;
    }
    color[i] = 2;
    return false;
}

int main()
{
    init();
}