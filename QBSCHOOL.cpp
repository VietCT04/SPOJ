#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
ll d[N], cnt[N];
vector<pair<ll, ll>> node[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
                ll k, u, v, c;
                cin >> k >> u >> v >> c;
                if (k == 1){
                        node[u].push_back({v, c});
                } else {
                        node[u].push_back({v, c});
                        node[v].push_back({u, c});
                }
        }
        for (int i = 2; i <= n; i++) d[i] = 1e18;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        cnt[1] = 1;
        pq.push({0, 1});
        while (pq.size()){
                pair<ll, ll> x = pq.top();
                pq.pop();
                if (x.first != d[x.second]) continue;
                for (auto j : node[x.second]){
                        if (d[j.first] == (x.first + j.second)){
                                cnt[j.first] += cnt[x.second];
                        }
                        if (d[j.first] > (x.first + j.second)){
                                d[j.first] = x.first + j.second;
                                cnt[j.first] = cnt[x.second];
                                pq.push({d[j.first], j.first});
                        }
                }
        }
        cout << d[n] << " " << cnt[n];
}
/*
*/
