#include <bits/stdc++.h>
using namespace std;
// de bai
// cho 2 so s va t lua chon lan luot cac chu so cua ca 2
// sao cho duoc so be nhat va thu tu cua cac so ban dau khong thay doi

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = " " + s;
    t = " " + t;
    string f[n + 1][m + 1];
    f[0][0] = "";
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = f[i - 1][0] + s[i];
    }
    for (int i = 1; i <= m; i++)
    {
        f[0][i] = f[0][i - 1] + t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + s[i], f[i][j - 1] + t[j]);
        }
    }
    cout << f[n][m] << endl;
}