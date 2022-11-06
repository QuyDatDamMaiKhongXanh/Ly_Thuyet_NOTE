// dung cho ca do thi co huong va vo huong
// algorithm
// duyet n-1 lan tat ca cac canh r cap nhat
// dung cho ca do thi co canh am nhung ko co chu trinh am
// dung de check do thi co chu trinh am
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
ll n, m, d[1001];
vector<edge> dscanh;
void init()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        dscanh.push_back({x, y, z});
    }
}
void bellmanford(ll s)
{
    for (ll i = 1; i <= n; i++)
    {
        d[i] = 1e9;
    }
    d[s] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto x : dscanh)
        {
            ll u = x.x, v = x.y, w = x.w;
            if (d[u] != 1e9 && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
void code_ktra_chu_trinh_am(ll s)
{
    for (ll i = 1; i <= n; i++)
    {
        d[i] = 1e9;
    }
    d[s] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto x : dscanh)
        {
            ll u = x.x, v = x.y, w = x.w;
            if (d[u] != 1e9 && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto x : dscanh)
        {
            ll u = x.x, v = x.y, w = x.w;
            if (d[u] != 1e9 && d[v] > d[u] + w)
            {
                cout << "Do thi co chu trinh am" << endl;
                return;
                d[v] = d[u] + w;
            }
        }
    }
}
int main()
{
    faster();
    init();
    bellmanford(1);
    return 0;
}