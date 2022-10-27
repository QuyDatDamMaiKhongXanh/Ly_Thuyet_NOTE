#include <bits/stdc++.h>
#define ll long long
using namespace std;

// co n chiec may va can tao ra t san pham
// ban biet thoi gian de tao ra 1 san pham cua 1 may
//  xac dinh time min de tao ra t san pham

ll n, t, a[1000001] = {0}, ans = 0;
bool check(ll mid)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mid / a[i];
    }
    return sum >= t;
}

int main()
{
    cin >> n >> t;
    ll left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        right = max(right, a[i]);
        left = min(left, a[i]);
    }
    right = right * t;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (check(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << ans << endl;
}