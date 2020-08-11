#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 2e5 + 5;
unordered_map<ll, ll> hb, ha, hc;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll m, n, p;
        cin >> m >> n >> p;
        for (int i = 1; i <= m; i++){
                ll a;
                cin >> a;
                ha[a] = 1;
        }
        for (int i = 1; i <= n; i++){
                ll b;
                cin >> b;
                hb[b] = 1;
        }
        m = ha.size();
        ll l = 1, ans = 0;
        for (int i = 1; i <= p; i++){
                ll c;
                cin >> c;
                if (hb[c]){
                        l = i + 1;
                        hc.clear();
                } else {
                        if (ha[c]){
                                hc[c] = 1;
                        }
                }
                if (hc.size() == m) ans = max(ans, i - l + 1);
        }
        cout << ans;
}
/*
*/
