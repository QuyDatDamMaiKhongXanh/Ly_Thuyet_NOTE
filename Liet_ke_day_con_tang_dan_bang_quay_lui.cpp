#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000001] = {0}, x[1000001] = {0}, n;
vector<string> v;

// test case
// 3 5
// 4 5
// 4 6
// 4 6 7
// 4 7
// 4 8
// 6 7
void back_track(ll pos, ll i)
{
    if (i > 2)
    {
        string s = "";
        for (int j = 1; j < i; j++)
        {
            string tam = to_string(x[j]);
            s += tam + " ";
        }
        v.push_back(s);
    }
    for (int j = pos; j <= n; j++)
    {
        if (a[j] > x[i - 1])
        {
            x[i] = a[j];
            back_track(j + 1, i + 1);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    back_track(1, 1);
    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << endl;
}