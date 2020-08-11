#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int
#define endl '\n'
const int N = 1e6 + 5;
ll f[500000][26], ed[500000], timer = 1, dp[300005];
ll mod = 1337377;
void add(string s){
        ll now = 1;
        for (int i = s.length() - 1; i >= 0; i--){
                ll a = s[i] - 'a';
                if (f[now][a] == 0) timer++, f[now][a] = timer;
                now = f[now][a];
        }
        ed[now] = 1;
}
string s;
void get(ll l, ll r){
        ll now = 1;
        for (int i = r; i >= l; i--){
                ll a = s[i] - 'a';
                if (f[now][a] == 0) break;
                now = f[now][a];
                if (ed[now]) dp[r] = (dp[r] + dp[i - 1]) % mod;
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        cin >> s;
        ll m = s.length();
        s = " " + s;
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++){
                string t;
                cin >> t;
                add(t);
        }
        dp[0] = 1;
        for (int i = 1; i <= m; i++){
                get(max(i - 99, 1), i);
        }
        cout << dp[m];
}
/*
*/
