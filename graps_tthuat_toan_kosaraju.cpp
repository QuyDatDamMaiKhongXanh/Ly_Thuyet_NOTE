// dem so thanh phan lien thong manh tren do thi co huong
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, visited[1001];
vector<ll> adj[1001], tadj[1001];
stack<ll> st;
void init()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        tadj[y].push_back(x);
    }
}
void dfs1(int i)
{
    visited[i] = 1;
    for (auto x : adj[i])
    {
        if (!visited[x])
        {
            dfs1(x);
        }
    }
    st.push(i);
}
void dfs2(int i)
{
    visited[i] = 1;
    cout << i << " ";
    for (auto x : tadj[i])
    {
        if (!visited[x])
        {
            dfs2(x);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    ll cnt = 0;
    init();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    memset(visited, 0, sizeof(visited));
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            cnt++;
            dfs2(top);
            cout << endl;
        }
    }
    cout << "cnt=" << cnt << endl;
    return 0;
}