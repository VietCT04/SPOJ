#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 2e5 + 5;
ll a, b, c, x, y, d, p, q;
void Euclid(){
        ll m = a, xm = 1, ym = 0;
        ll n = b, xn = 0, yn = 1;
        ll r, xr, yr;
        while (n != 0){
                ll q = m / n;
                r = m - n * q; xr = xm - xn * q; yr = ym - yn * q;
                m = n; xm = xn; ym = yn;
                n = r; xn = xr; yn = yr;
        }
        d = m;
        x = xm * c / d;
        y = ym * c / d;
        d = abs(d);
        p = -b / d;
        q = a / d;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll b1, b2;
        cin >> a >> b1 >> b >> b2;
        c = b2 - b1;
        b = -b;
        if (a == b && a == 0) return cout << "0 0", 1;
        if (a == 0) return cout << "0 " << c/b, 1;
        if (b == 0) return cout << c/a << " 0", 1;
        Euclid();
        x = (x % p + p) % p;
        y = (c - a * x) / b;
        if (y >= 0){
                cout << x << " " << y;
                return 0;
        }
        y = (y % q + q) % q;
        x = (c - b * y) / a;
        cout << x << " " << y;
}
/*
*/
