#include <bits/stdc++.h>
using namespace std;
 
#define ll int
#define endl '\n'
const int N = 5e4 + 5;
struct viet{
        ll mx, mn;
};
viet st[N * 4];
ll a[N];
void upd(ll k, ll l, ll r, ll x, ll v){
        if (x < l || x > r) return;
        if (l == r){
                st[k].mn = v;
                st[k].mx = v;
                return;
        }
        ll mid = (l + r) >> 1;
        upd(k << 1, l, mid, x, v);
        upd(k << 1 | 1, mid + 1, r, x, v);
        st[k].mx = max(st[k << 1 | 1].mx ,st[k << 1].mx);
        st[k].mn = min(st[k << 1 | 1].mn, st[k << 1].mn);
}
viet get(ll k, ll l, ll r, ll x, ll y){
        if (x > r || y < l) return {0ll, 1000000000};
        if (x <= l && y >= r){
                return st[k];
        }
        ll mid = (l + r) >> 1;
        viet res;
        viet left = get(k << 1, l, mid, x, y);
        viet right = get(k << 1 | 1, mid + 1, r, x, y);
        res.mn = min(left.mn, right.mn);
        res.mx = max(left.mx, right.mx);
        return res;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("test.txt", "r", stdin);
        ll n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++){
                ll a;
                cin >> a;
                upd(1, 1, n, i, a);
        }
        for (int i = 1; i <= q; i++){
                ll l, r;
                cin >> l >> r;
                viet x = get(1, 1, n, l, r);
                cout << x.mx - x.mn << endl;
        }
}
