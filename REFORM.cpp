#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 2e5 + 5;
ll u[N], v[N], n, m, par[N], sz[N];
vector<pair<ll, pair<ll, ll>>> D;
ll ans = 0;
void rollback(ll now){
        while (D.size() > now){
                par[D.back().first] = D.back().second.second;
                sz[D.back().first] = D.back().second.first;
                D.pop_back();
        }
}
ll find_set(ll u){
        if (par[u] == u) return u;
        return find_set(par[u]);
}
void dsu(ll u, ll v){
        u = find_set(u);
        v = find_set(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        D.push_back({u, {sz[u], par[u]}});
        D.push_back({v, {sz[v], par[v]}});
        sz[u] += sz[v];
        par[v] = u;
}
void DC(ll l, ll r){
        if (l > r) return;
        if (l == r){
                if (find_set(u[l]) == find_set(v[l])){
                        if (sz[find_set(u[l])] == n) ans = ans + n * (n - 1) / 2 - m;
                        else ans = ans + sz[find_set(u[l])] * (n - sz[find_set(u[l])]);
                } else if ((sz[find_set(u[l])] + sz[find_set(v[l])]) == n){
                        ans = ans + sz[find_set(u[l])] * sz[find_set(v[l])] - 1;
                }
                //cout << ans << " ";
                return;
        }
        ll mid = (l + r) >> 1;
        ll now = D.size();
        for (int i = mid + 1; i <= r; i++){
                dsu(u[i], v[i]);
        }
        DC(l, mid);
        rollback(now);
        for (int i = l; i <= mid; i++){
                dsu(u[i], v[i]);
        }
        DC(mid + 1, r);
        rollback(now);
}
unordered_map<ll, ll> mem;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
                par[i] = i;
                sz[i] = 1;
        }
        for (int i = 1; i <= m; i++){
                cin >> u[i] >> v[i];
        }
        DC(1, m);
        for (int i = 1; i <= n; i++){
                par[i] = i;
                sz[i] = 1;
        }
        for (int i = 1; i <= m; i++) dsu(u[i], v[i]);
        for (int i = 1; i <= n; i++) {
                mem[find_set(i)] = 1;
        }
        if (mem.size() > 2) ans = 0;
        cout << ans;
}
/*
*/
