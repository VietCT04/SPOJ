#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int
#define endl '\n'
const int N = 1e5 + 5;
ll dp[105][2005], v[105], c[105];
vector<ll> node[105];
ll n, m;
void dfs(ll u, ll p, ll cost){
        if (cost > m) return;
        for (auto j : node[u]){
                if (j == p) continue;
                for (int i = cost + c[j]; i <= m; i++){
                        dp[j][i] = dp[u][i - c[j]] + v[j];
                }
                dfs(j, u, cost + c[j]);
                for (int i = cost + c[j]; i <= m; i++){
                        dp[u][i] = max(dp[u][i], dp[j][i]);
                }
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        cin >> n >> m;
        for (int i = 2; i <= n; i++) cin >> v[i];
        for (int i = 2; i <= n; i++) cin >> c[i];
        for (int i = 1; i < n; i++){
                ll u, v;
                cin >> u >> v;
                node[u].push_back(v);
                node[v].push_back(u);
        }
        dfs(1, 1, 0);
        ll ans = 0;
        for (int i = 0; i <= m; i++){
                ans = max(ans, dp[1][i]);
        }
        cout << ans;
}
/*
*/
