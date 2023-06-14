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
ll n, m, parent[1001], sz[1001];
vector<edge> v;
void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v.push_back({x, y, w});
        sz[i] = 1;
        parent[i] = i;
    }
    sort(v.begin(), v.end(), [](edge x, edge y) -> bool
         { return x.w < y.w; });
}
ll find(ll u)
{
    if (parent[u] == u)
        return u;
    else
        return parent[u] = find(parent[u]);
}
bool uni(ll x, ll y)
{
    x = find(x);
    y = find(y);
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
void kruskal()
{
    vector<edge> mst;
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (cnt == n - 1)
            break;
        ll x = v[i].x;
        ll y = v[i].y;
        ll w = v[i].w;
        if (uni(x, y))
        {
            sum += w;
            cnt++;
            mst.push_back({x, y, w});
        }
    }
    if (cnt != n - 1)
    {
        cout << "Do thi khong lien thong" << endl;
    }
    else
    {
        for (auto it : mst)
        {
            cout << it.x << " " << it.y << " " << it.w << endl;
        }
        cout << "Min=" << sum << endl;
    }
}
int main()
{
    faster();
    init();
    kruskal();
    return 0;
}
