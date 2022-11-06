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
vector<edge> v;
void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v.push_back({x, y, w});
    }
    sort(all(v), [](edge x, edge y) -> bool
         { return x.w < y.w; });
}
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
}
void prim()
{
    visited[1] = true;
    ll cnt = 0;
    ll sum = 0;
    while (!check())
    {
        if (cnt == n - 1)
            break;
        for (ll i = 0; i < m; i++)
        {
            ll x = v[i].x;
            ll y = v[i].y;
            ll w = v[i].w;
            if (visited[x] != visited[y])
            {
                visited[x] = visited[y] = true;
                cnt++;
                sum += w;
                break;
            }
        }
    }
    if (cnt != n - 1)
        cout << "Do thi khong lien thong" << endl;
    else
        cout << sum << endl;
}
int main()
{
    faster();
    init();
    prim();
}