// sol này AC trên cf nhưng TLE trên spoj muốn AC phải cài BIT
#include <bits/stdc++.h>

using namespace std;

#define ll int
#define ull unsigned long long
#define endl '\n'
const int N = 1e5 + 5;
ll a[10005], b[10005];
ll st[100005 * 3];
ll mod = 5000000;
ll lim = 1e5 + 1;
ll add(int x, int y){
        if ((x + y) >= mod) return x + y - mod;
        else return x + y;
}
void upd(ll k, ll l, ll r, ll x, ll v){
        if (l > x || x > r) return;
        if (l == r){
                st[k] = add(st[k], v);
                return;
        }
        ll mid = (l + r) >> 1;
        upd(k << 1, l, mid, x, v);
        upd(k << 1 | 1, mid + 1, r, x, v);
        st[k] = add(st[k << 1], st[k << 1 | 1]);
}
ll get(ll k, ll l, ll r, ll x, ll y){
        if (x > r || y < l) return 0;
        if (x <= l && y >= r) return st[k];
        ll mid = (l + r) >> 1;
        return add(get(k << 1, l, mid, x, y), get(k << 1 | 1, mid + 1, r, x, y));
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("tests.in", "r")){
                freopen("tests.in", "r", stdin);
                //freopen("BONUS.OUT", "w", stdout);
        }
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
                a[i]++;
        }
        for (int i = 1; i <= n; i++){
                b[i] = 1;
        }
        for (int i = 2; i <= k; i++){
                memset(st, 0, sizeof(st));
                for (int i = 1; i <= n; i++){
                        upd(1, 1, lim, a[i], b[i]);
                        b[i] = get(1, 1, lim, 1, a[i] - 1);
                }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                ans = add(ans, b[i]);
        }
        cout << ans;
}
/*
*/
