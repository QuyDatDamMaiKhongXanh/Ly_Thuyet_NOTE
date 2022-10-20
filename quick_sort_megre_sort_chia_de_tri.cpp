#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int l, int r)
{
    int i = l - 1;
    int pivot = a[r];
    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[r], a[i]);
    return i;
}
void quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int pos = partition(a, l, r);
        quick_sort(a, l, pos - 1);
        quick_sort(a, pos + 1, r);
    }
}
void quick_sort2(int a[], int l, int r)
{
    if (l >= r)
        return;
    int pivot = (l + r) / 2;
    int i = l;
    int j = r;
    do
    {
        while (a[i] < a[pivot])
            i++;
        while (a[j] > a[pivot])
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    quick_sort2(a, l, j);
    quick_sort2(a, i, r);
}
// merge sort
void merge_ok(int a[], int l, int m, int r)
{
    vector<int> v1(a + l, a + m + 1);
    vector<int> v2(a + m + 1, a + r + 1);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), a + l);
}
void merge_sort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge_ok(a, l, mid, r);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;
    merge_sort(a, 0, n - 1);
    for (auto x : a)
        cout << x << " ";
}