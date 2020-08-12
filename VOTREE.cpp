#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 1e6 + 5;
const int lg = 16;
ll tin[70005], timer = 0, dp[70005][17], dep[70005], pos[70005];
vector<ll> node[70005];
void dfs(ll u, ll p){
        timer++;
        tin[u] = timer;
        pos[timer] = u;
        for (int i = 1; i <= lg; i++) dp[u][i] = dp[dp[u][i - 1]][i - 1];
        for (auto j : node[u]){
                if (j == p) continue;
                dp[j][0] = u;
                dep[j] = dep[u] + 1;
                dfs(j, u);
        }
}
ll st[70005 * 4][2];
void build(ll k, ll l, ll r){
        if (l == r){
                st[k][0] = tin[l];
                st[k][1] = tin[l];
                return;
        }
        ll mid = (l + r) >> 1;
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
        st[k][0] = min(st[k << 1][0], st[k << 1 | 1][0]);
        st[k][1] = max(st[k << 1][1], st[k << 1 | 1][1]);
}
pair<ll, ll> get(ll k, ll l, ll r, ll x, ll y){
        if (x > r || y < l) return {1e9, 0};
        if (x <= l && y >= r) return {st[k][0], st[k][1]};
        ll mid = (l + r) >> 1;
        pair<ll, ll> lf = get(k << 1, l, mid, x, y);
        pair<ll, ll> rt = get(k << 1 | 1, mid + 1, r, x, y);
        return {min(lf.first, rt.first), max(lf.second, rt.second)};
}
ll LCA(ll u, ll v){
        if (dep[u] > dep[v]) swap(u, v);
        ll dis = dep[v] - dep[u];
        for (int i = lg; i >= 0; i--){
                if (dis & (1 << i)){
                        v = dp[v][i];
                }
        }
        if (u == v) return v;
        for (int i = lg; i >= 0; i--){
                if (dp[u][i] != dp[v][i]){
                        v = dp[v][i];
                        u = dp[u][i];
                }
        }
        return dp[u][0];
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("test.txt", "r")){
                freopen("test.txt", "r", stdin);
                //freopen("test.OUT", "w", stdout);
        }
        ll n, q;
        cin >> n >> q;
        for (int i = 1; i < n; i++){
                ll u, v;
                cin >> u >> v;
                node[u].push_back(v);
                node[v].push_back(u);
        }
        dfs(1, 1);
        build(1, 1, n);
        while (q--){
                ll u, v;
                cin >> u >> v;
                pair<ll, ll> x = get(1, 1, n, u, v);
                cout << LCA(pos[x.first], pos[x.second]) << endl;
        }
}
/*
*/
