#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 1e6 + 5;
ll timer = 0;
vector<ll> node[10005];
stack<ll> s;
unordered_map<ll, ll> onstack;
ll cnt = 0, low[10005], ids[10005], vis[10005];
void dfs(ll u){
        timer++;
        vis[u] = 1;
        ids[u] = low[u] = timer;
        s.push(u);
        onstack[u] = 1;
        for (auto j : node[u]){
                if (vis[j] == 0){
                        dfs(j);
                        low[u] = min(low[u], low[j]);
                } else if (onstack[j]){
                        low[u] = min(low[u], ids[j]);
                }
        }
        if (low[u] == ids[u]){
                while (true){
                        ll x = s.top();
                        s.pop();
                        low[x] = low[u];
                        onstack[x] = 0;
                        if (x == u) break;
                }
                cnt++;
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("test.txt", "r")){
                freopen("test.txt", "r", stdin);
                //freopen("test.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
                ll u, v;
                cin >> u >> v;
                node[u].push_back(v);
        }
        for (int i = 1; i <= n; i++){
                if (!ids[i]){
                        dfs(i);
                }
        }
        cout << cnt;
}
/*
*/
