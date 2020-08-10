#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 4e5 + 5;
vector<pair<ll, ll>> node[N];
ll vis[N], tin[N], low[N], e[N];
ll timer = 0, ans = 0;
void dfs(ll u){
        vis[u] = true;
        tin[u] = low[u] = timer++;
        for (auto to : node[u]){
                if (e[to.second]) continue;
                if (vis[to.first]){
                        low[u] = min(low[u], tin[to.first]);
                } else {
                        e[to.second] = 1;
                        dfs(to.first);
                        low[u] = min(low[u], low[to.first]);
                        if (low[to.first] > tin[u]) ans++;
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
        ll n;
        cin >> n;
        ll cnt = 0;
        for (int i = 1; i < n; i++){
                ll u, v;
                cin >> u >> v;
                cnt++;
                node[u].push_back({v, cnt});
                node[v].push_back({u, cnt});
        }
        ll m;
        cin >> m;
        while (m--){
                ll u, v;
                cin >> u >> v;
                cnt++;
                node[u].push_back({v, cnt});
                node[v].push_back({u, cnt});
        }
        for (int i = 1; i <= n; i++){
                if (!vis[i]){
                        dfs(i);
                }
        }
        cout << ans;
}
/*
*/
