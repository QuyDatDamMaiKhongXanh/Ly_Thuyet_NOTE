#include <bits/stdc++.h>
using namespace std;
int n, a[100];
vector<string> v;

void out(int x)
{
    string res = "";
    for (int i = 1; i <= x; i++)
    {
        res += to_string(a[i]);
        if (i != x)
            res += "+";
    }
    v.push_back(res);
}

void track(int i, int begin, int sum)
{
    for (int j = begin; j >= 1; j--)
    {
        if (sum + j <= n)
        {
            a[i] = j;
            if (sum + j == n)
                out(i);
            else
                track(i + 1, j, sum + j);
        }
    }
}

int main()
{
    cin >> n;
    track(1, n, 0);
    cout << v.size() << endl;
    for (string x : v)
        cout << x << endl;
}