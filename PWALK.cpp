#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
const int lg = 10;
ll des, ans = 0;
bool flag = false;
vector<pair<ll, ll>> node[1005];
void dfs(ll u, ll p){
        if (u == des) {
                cout << ans << endl;
                flag = true;
                return;
        }
        for (auto j : node[u]){
                if (j.first == p) continue;
                ans += j.second;
                dfs(j.first, u);
                ans -= j.second;
                if (flag) return;
        }
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
                ll u, v, c;
                cin >> u >> v >> c;
                node[u].push_back({v, c});
                node[v].push_back({u, c});
        }
        while (q--){
                ll u;
                cin >> u >> des;
                flag = false;
                ans = 0;
                dfs(u, u);
        }
}
/*
*/
