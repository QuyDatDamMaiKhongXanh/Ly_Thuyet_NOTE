#include <bits/stdc++.h>
using namespace std;
int a[1000001] = {0}, cnt = 0, n;
bool col[1000001] = {0}, cheo1[1000001] = {0}, cheo2[1000001] = {0};
// bai toan n quan hau
int c[1001][1001], x[1000001] = {0}, ans = INT_MAX, visited[1000001] = {0}, cmin = INT_MAX;
void n_quan_hau(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!col[j] && !cheo1[i + j - 1] && !cheo2[n + i - j])
        {
            a[i] = j;
            col[j] = true;
            cheo1[i + j - 1] = true;
            cheo2[n + i - j] = true;
            if (i == n)
            {
                cnt++;
            }
            else
            {
                n_quan_hau(i + 1);
            }
            col[j] = false;
            cheo1[i + j - 1] = false;
            cheo2[n + i - j] = false;
        }
    }
}

void main_n_quan_hau()
{
    cin >> n;
    n_quan_hau(1);
    cout << "Tong so cach = " << cnt << endl;
}

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j])
            {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}
void bai_toan_nguoi_du_lich_code_quay_lui(int i, int sum)
{
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            visited[j] = true;
            x[i] = j;
            sum += c[x[i - 1]][x[i]];
            if (i == n)
            {
                ans = min(ans, sum + c[x[i]][1]);
            }
            else
                bai_toan_nguoi_du_lich_code_quay_lui(i + 1, sum);
            sum -= c[x[i - 1]][x[i]];
            visited[j] = false;
        }
    }
}
void bai_toan_nguoi_du_lich_code_nhanh_can(int i, int sum)
{
    for (int j = 2; j <= n; j++)
    {
        if (!visited[j])
        {
            x[i] = j;
            visited[j] = true;
            sum += c[x[i - 1]][x[i]];
            if (i == n)
            {
                ans = min(ans, sum + c[x[i]][1]);
            }
            else
            {
                if (sum + (n - i + 1) * cmin < ans)
                {
                    bai_toan_nguoi_du_lich_code_nhanh_can(i + 1, sum);
                }
            }
            visited[j] = false;
            sum -= c[x[i - 1]][x[i]];
        }
    }
}
void main_bai_toan_nguoi_du_lich()
{
    init();
    visited[1] = 1, x[1] = 1;
    bai_toan_nguoi_du_lich_code_quay_lui(2, 0);
    cout << ans << endl;
}
void main_nguoi_du_lich_code_nhanh_can()
{
    init();
    x[1] = 1;
    visited[1] = true;
    bai_toan_nguoi_du_lich_code_nhanh_can(2, 0);
    cout << "Chi phi nho nhat la:" << ans << endl;
}
int main()
{
    main_nguoi_du_lich_code_nhanh_can();
}