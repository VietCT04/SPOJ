#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
const int lg = 18;
vector<ll> node[N];
ll dp[N][19], dep[N];
ll ans, res;
void dfs(ll u, ll p){
        for (int i = 1; i <= lg; i++) dp[u][i] = dp[dp[u][i - 1]][i - 1];
        for (auto j : node[u]){
                if (j == p) continue;
                dep[j] = dep[u] + 1;
                dp[j][0] = u;
                dfs(j, u);
        }
}
ll LCA(ll u, ll v){
        if (dep[u] > dep[v]) swap(u, v);
        ll dit = dep[v] - dep[u];
        for (int i = lg; i >= 0; i--){
                if (dit & (1 << i)){
                        v = dp[v][i];
                }
        }
        if (u == v) return u;
        for (int i = lg; i >= 0; i--){
                if (dp[v][i] != dp[u][i]){
                        v = dp[v][i];
                        u = dp[u][i];
                }
        }
        return dp[u][0];
}
ll dis(ll u, ll v){
        ll lca = LCA(u, v);
        return dep[u] + dep[v] - 2 * dep[lca];
}
void check(ll u, ll x, ll y, ll z){
        ll cost = dis(u, x) + dis(u, y) + dis(u, z);
        if (cost < res){
                res = cost;
                ans = u;
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n;
        while(cin >> n){
                if (n == 0) return 0;
                for (int i = 1; i <= n; i++) node[i].clear();
                for (int i = 1; i <= n; i++) for (int j = 0; j <= lg; j++) dp[i][j] = 0;
                for (int i = 1; i <= n; i++) dep[i] = 0;
                for (int i = 1; i < n; i++){
                        ll u, v;
                        cin >> u >> v;
                        node[u].push_back(v);
                        node[v].push_back(u);
                }
                dfs(1, 1);
                ll m;
                cin >> m;
                ll root = 1;
                while (m--){
                        char task;
                        cin >> task;
                        if (task == '!'){
                                cin >> root;
                        } else {
                                ll u, v;
                                cin >> u >> v;
                                res = 1e18;
                                check(u, u, v, root);
                                check(v, u, v, root);
                                check(root, u, v, root);
                                check(LCA(u, v), u, v, root);
                                check(LCA(v, root), u, v, root);
                                check(LCA(u, root), u, v, root);
                                cout << ans << endl;
                        }
                }
        }
}
/*
*/
