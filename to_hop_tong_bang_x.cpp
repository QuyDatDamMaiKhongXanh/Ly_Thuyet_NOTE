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
ll n, s, cnt = 0;
ll a[1000001];
vector<ll> v;
vector<string> res;
void back_track(ll begin, ll i, ll sum)
{
    for (ll j = begin; j <= n; j++)
    {
        if (sum + a[j] <= s)
        {
            v.push_back(a[j]);
            sum += a[j];
            if (sum == s)
            {
                string tam = "";
                cnt++;
                tam += "{";
                for (ll k = 0; k < v.size(); k++)
                {
                    if (k != v.size() - 1)
                        tam = tam + to_string(v[k]) + " ";
                    else
                    {
                        tam = tam + to_string(v[k]) + "}";
                    }
                }
                res.push_back(tam);
            }
            else
                back_track(j, i + 1, sum);
            v.pop_back();
            sum -= a[j];
        }
    }
}
int main()
{
    faster();
    cin >> n >> s;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    back_track(1, 1, 0);
    cout << cnt << endl;
    for (auto x : res)
    {
        cout << x << endl;
    }
}