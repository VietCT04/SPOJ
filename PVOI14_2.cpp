#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int
#define endl '\n'
const int N = 3e6 + 5;
ll n, a[1000006];
ll get(ll i, ll j){
        return (i - 1) * n + j;
}
vector<pair<ll, ll>> d[1000006];
ll lab[1000006];
ll ans = 1;
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
        ans = max(ans, -lab[u]);
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        cin >> n;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                        cin >> a[get(i, j)];
                        if (i > 1) d[abs(a[get(i, j)] - a[get(i - 1, j)])].push_back({get(i, j), get(i - 1, j)});
                        if (j > 1) d[abs(a[get(i, j)] - a[get(i, j - 1)])].push_back({get(i, j), get(i, j - 1)});
                }
        }
        memset(lab, -1, sizeof(lab));
        for (int i = 0; i <= 1000000; i++){
                if ((ll)d[i].size() == 0) continue;
                for (auto j : d[i]){
                        dsu(j.first, j.second);
                }
                for (auto j : d[i]){
                        lab[j.first] = -1;
                        lab[j.second]    = -1;
                }
        }
        cout << ans;
}
/*
*/
