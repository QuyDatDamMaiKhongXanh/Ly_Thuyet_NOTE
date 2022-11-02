#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a, 0, sizeof(a))
using namespace std;
ll n, m, cnt = 0, dem = 0;
bool visited[1001] = {0};
vector<ll> adj[1001];
void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs1(int i) // dinh tru
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (!visited[x])
            dfs1(x);
    }
}
void dfs2(int i, int s, int t) // canh cau
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (!visited[x])
        {
            if ((x == s && i == t) || (x == t && i == s))
                continue;
            else
                dfs2(x, s, t);
        }
    }
}
void dinh_tru()
{
    for (int i = 1; i <= n; i++)
    {
        ll dem2 = 0;
        visited[i] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                dem2++;
                dfs1(i);
            }
        }
        if (dem2 > cnt)
            dem++;
        ms(visited);
    }
}
void canh_cau()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll dem2 = 0;
            for (int k = 1; k <= n; k++)
            {
                if (!visited[k])
                {
                    dem2++;
                    dfs2(k, i, j);
                }
            }
            if (dem2 > cnt)
                dem++;
            ms(visited);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs1(i);
        }
    }
    ms(visited);
    // dinh_tru();
    canh_cau();
    cout << dem / 2 << endl;
}