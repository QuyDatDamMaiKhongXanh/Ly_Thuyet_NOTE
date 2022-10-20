#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, V;
    cin >> n >> V;
    int w[n + 1] = {0};
    int v[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int f[n + 1][V + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j > w[i])
            {
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << f[n][V] << endl;
}