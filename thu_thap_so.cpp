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

int main()
{
    faster();
    // thu thap so vao tui sao cho tui tang dan
    ll n;
    cin >> n;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
}