#include <bits/stdc++.h>
#define ll long long
using namespace std;

// cho mang co n phan tu va 1 so nguyen k nhiem vu cua ban la hay chia
// mang thanh k nhom sao cho tong lon nhat cua 1 nhom la nho nhat

ll n, k, a[1000001] = {0};
bool check(ll mid)
{
    ll cnt = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
            return false;
        sum += a[i];
        if (sum > mid)
        {
            cnt++;
            sum = a[i];
        }
    }
    if (sum > 0)
        cnt++;
    return cnt <= k;
}
int main()
{
    ll left = 0, right = 0, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        left = max(left, a[i]);
        right += a[i];
    }
    while (left <= right)
    {
        ll mid = (right + left) / 2;
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