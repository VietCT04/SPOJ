#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 1e6 + 5;
ll dp[250050][26], timer = 1, ed[250050], f[250050];
void add(string s){
        ll now = 1;
        for (int i = 0; i < s.length(); i++){
                ll a = s[i] - 'a';
                if (dp[now][a] == 0) timer++, dp[now][a] = timer;
                now = dp[now][a];
        }
        ed[now] = 1;
}
void dfs(ll u){
        for (int i = 0; i < 26; i++){
                if (dp[u][i]){
                        dfs(dp[u][i]);
                        f[u] = max(f[u], f[dp[u][i]]);
                }
        }
        f[u] = f[u] + ed[u];
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("test.txt", "r")){
                freopen("test.txt", "r", stdin);
                //freopen("test.OUT", "w", stdout);
        }
        ll m;
        cin >> m;
        for (int i = 1; i <= m; i++){
                string s;
                cin >> s;
                add(s);
        }
        dfs(1);
        cout << f[1];
}
/*
*/
