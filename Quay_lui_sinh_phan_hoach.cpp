#include <bits/stdc++.h>
using namespace std;
int n, a[100];
vector<string> v;
// ex: de bai : in ra phan hoach cua so n
// input : 7
// output :
// 15 so luong cach phan hoach
// 7
// 6+1
// 5+2
// 5+1+1
// 4+3
// 4+2+1
// 4+1+1+1
// 3+3+1
// 3+2+2
// 3+2+1+1
// 3+1+1+1+1
// 2+2+2+1
// 2+2+1+1+1
// 2+1+1+1+1+1
// 1+1+1+1+1+1+1
void out(int x) // in ra cau hinh
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
// ta thay cau hinh la tong giam dan tu so dau
// nen ta lam 1 for giam dan tu gia tri ban dau
// va backtrack lai
// i la duy tri chi so mang
// begin la gia tri bat dau
// check xem da du de in ra cau hinh hay chua
void track(int i, int begin, int sum)
{
    for (int j = begin; j >= 1; j--)
    {
        if (sum + j <= n) // dieu kien de gan i
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