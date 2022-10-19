#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
using namespace std;
// euclid mo rong
// cong thuc x=y1 y=x1-(a/b)*y1;
int x, y, g;
void extended_gcd(int a, int b)
{
    if (b == 0)
    {
        g = a;
        x = 1;
        y = 0;
        return;
    }
    extended_gcd(b, a % b);
    int tam = x;
    x = y;
    y = tam - a / b * y;
}
// nghich dao modul [a/b]%c=(a%c)*(nghichdaomodul(b)%c)%c
// dieu kien de ton tai nghich dao modul gcd(b,c)==1
void inverse1()
{
    int b, mod;
    cin >> b >> mod;
    // ta co nghich dao modul b duoi modul mod
    extended_gcd(b, mod);
    if (g != 1)
        cout << "Ko ton tai nghich dao modul " << endl;
    else
        cout << (x % mod + mod) % mod;
}
ll powmod(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
        {
            res *= 1ll * a;
            res %= m;
        }
        a *= a;
        a %= m;
        b = b >> 1;
    }
    return res;
}
ll inverse2(ll a, ll m)
{
    // dinh ly fermat neu p la 1 so nguyen to va a ko chia het cho b
    // thi a^(p-1)=1%p;
    // chot lai a^-1=a^(p-2)%p;
    return powmod(a, m - 2, m);
}
ll f[1000001] = {0};
void ex()
{
    // ex: tinh ckn mod 1e9+7 voi n la so nguyen lon <=1e18
    ll k, n;
    cin >> k >> n;
    f[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
    ll res = f[n];
    ll tam1 = inverse2(f[k], mod) % mod;
    ll tam2 = inverse2(f[n - k], mod) % mod;
    res *= tam1;
    res %= mod;
    res *= tam2;
    res %= mod;
    cout << res << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ex();
}