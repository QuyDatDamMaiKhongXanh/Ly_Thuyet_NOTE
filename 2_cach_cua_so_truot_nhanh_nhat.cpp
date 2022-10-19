#include <bits/stdc++.h>
#define ll long long
using namespace std;
// ex:in ra so max trong tung o cua so
// cach nhanh nhat dung deque
// cach 2 dung multiset
int n, k;
// cach 1
void deque_ok()
{
    deque<int> qe;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        if (qe.empty())
        {
            qe.push_back(i);
        }
        else
        {
            while (!qe.empty() && a[i] >= a[qe.back()])
            {
                qe.pop_back();
            }
            qe.push_back(i);
        }
    }
    cout << a[qe.front()] << " ";
    for (int i = k; i < n; i++)
    {
        if (!qe.empty() && qe.front() <= (i - k))
            qe.pop_front();
        while (!qe.empty() && a[i] > a[qe.back()])
        {
            qe.pop_back();
        }
        qe.push_back(i);
        cout << a[qe.front()] << " ";
    }
    cout << endl;
}
// cach 2 dung multiset
void multi_set()
{
    int a[n];
    multiset<int> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        se.insert(a[i]);
    }
    cout << *se.rbegin() << " ";
    for (int i = k; i < n; i++)
    {
        se.erase(se.find(a[i - k]));
        se.insert(a[i]);
        cout << *se.rbegin() << " ";
    }
    cout << endl;
}
int main()
{
    cin >> n >> k;
    deque_ok();
    multi_set();
}