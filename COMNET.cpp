#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 1e6 + 5;
ll u[N], v[N], c[N], lab[N];
void init(ll n){
        for (int i = 1; i <= n; i++) lab[i] = -1;
}
ll find_set(ll u){
        if (lab[u] < 0) return u;
        return lab[u] = find_set(lab[u]);
}
void dsu(ll u, ll v){
        u = find_set(u);
        v = find_set(v);
        if (u == v) return;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll t;
        cin >> t;
        while (t--){
                ll n, m, q;
                cin >> n >> m >> q;
                for (int i = 1; i <= m; i++){
                        cin >> u[i] >> v[i] >> c[i];
                }
                while (q--){
                        ll k;
                        cin >> k;
                        ll s;
                        cin >> s;
                        vector<pair<ll, ll>> mem;
                        for (int i = 1; i <= s; i++){
                                ll x, y;
                                cin >> x >> y;
                                mem.push_back({x, c[x]});
                                c[x] = y;
                        }
                        init(n);
                        for (int i = 1; i <= m; i++){
                                if (c[i] < c[k]) dsu(u[i], v[i]);
                        }
                        if (find_set(u[k]) != find_set(v[k])) cout << "NO" << endl;
                        else cout << "YES" << endl;
                        for (auto j : mem) c[j.first] = j.second;
                }
        }
}
/*
*/
