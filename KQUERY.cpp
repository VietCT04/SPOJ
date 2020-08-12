#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
pair<ll,ll> a[N];
ll n, st[N * 4], ans[N];
struct ok{
        ll id, l, r, k;
};
ok q[N];
bool cmp(ok x, ok y){
        return x.k < y.k;
}
void built(ll k, ll l, ll r){
        if (l == r){
                st[k] = 1;
                return;
        }
        ll mid = (l + r) >> 1;
        built(k << 1, l, mid);
        built(k << 1 | 1, mid + 1, r);
        st[k] = st[k << 1] + st[k << 1 | 1];
}
void upd(ll k, ll l, ll r, ll x){
        if (x > r || x < l) return;
        if (l == r) {
                st[k] = 0;
                return;
        }
        ll mid = (l + r) >> 1;
        upd(k << 1, l, mid, x);
        upd(k << 1 | 1, mid + 1, r, x);
        st[k] = st[k << 1] + st[k << 1 | 1];
}
ll get(ll k, ll l, ll r, ll x, ll y){
        if (x > r || y < l) return 0;
        if (x <= l && y >= r) return st[k];
        ll mid = (l + r) >> 1;
        return get(k << 1, l, mid, x, y) + get(k << 1 | 1, mid + 1, r, x, y);
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> a[i].first;
                a[i].second = i;
        }
        ll t;
        cin >> t;
        for (int i = 1; i <= t; i++) {
                cin >> q[i].l >> q[i].r >> q[i].k;
                q[i].id = i;
        }
        built(1, 1, n);
        sort(a + 1, a + n + 1);
        sort(q + 1, q + t + 1, cmp);
        ll now = 1;
        for (int i = 1; i <= t; i++){
                while (a[now].first <= q[i].k && now <= n){
                        upd(1, 1, n, a[now].second);
                        now++;
                }
                ans[q[i].id] = get(1, 1, n, q[i].l, q[i].r);
        }
        for (int i = 1; i <= t; i++){
                cout << ans[i] << endl;
        }
}
