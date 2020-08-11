#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 1e6 + 5;
vector<pair<ll, ll>> node[1005];
ll dp[1005][1005], l[1005], r[1005];
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
                ll u, v, r;
                cin >> u >> v >> r;
                node[u].push_back({max(v - r + 1, 1), min(v + r - 1, n)});
                for (int j = u - 1; j >= max(u - r + 1, 1); j--){
                        ll l = sqrt((r * 10 - 5) * (r * 10 - 5) - ((u - j) * 10 - 5) * ((u - j) * 10 - 5));
                        if ((l % 10) != 5 || (l * l) != ((r * 10 - 5) * (r * 10 - 5) - ((j - u) * 10 - 5) * ((j - u) * 10 - 5))) l += 10;
                        l = (l + 5) / 10;
                        node[j].push_back({max(v - l + 1, 1), min(v + l - 1, n)});
                }
                for (int j = u + 1; j <= min(u + r - 1, n); j++){
                        ll l = sqrt((r * 10 - 5) * (r * 10 - 5) - ((j - u) * 10 - 5) * ((j - u) * 10 - 5));
                        if ((l % 10) != 5 || (l * l) != ((r * 10 - 5) * (r * 10 - 5) - ((j - u) * 10 - 5) * ((j - u) * 10 - 5))) l += 10;
                        l = (l + 5) / 10;
                        node[j].push_back({max(v - l + 1, 1), min(v + l - 1, n)});
                }
        }
        for (int i = 1; i <= n; i++) sort(node[i].begin(), node[i].end());
        ll cnt = 0;
        for (int i = 1; i <= n; i++){
                ll mx = 0;
                ll l = 0;
                for (int j = 1; j <= n; j++){
                        while (l < node[i].size() && node[i][l].first == j){
                                mx = max(mx, node[i][l].second);
                                l++;
                        }
                        if (mx >= j){
                                dp[i][j] = 0;
                                cnt++;
                        } else {
                                dp[i][j] = 1;
                        }
                }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                        if (dp[i][j] == 0) dp[i][j] = 0;
                        else dp[i][j] += dp[i - 1][j];
                }
                stack<ll> s;
                for (int j = 1; j <= n; j++){
                        while (s.size()){
                                if (dp[i][j] <= dp[i][s.top()]) s.pop();
                                else break;
                        }
                        if (s.size()) l[j] = s.top() + 1;
                        else l[j] = 1;
                        s.push(j);
                }
                while (s.size()) s.pop();
                for (int j = n; j >= 1; j--){
                        while (s.size()){
                                if (dp[i][j] <= dp[i][s.top()]) s.pop();
                                else break;
                        }
                        if (s.size()) r[j] = s.top() - 1;
                        else r[j] = n;
                        s.push(j);
                }
                for (int j = 1; j <= n; j++){
                        ans = max(ans, (r[j] - l[j] + 1) * dp[i][j]);
                }
        }
        cout << ans << " " << cnt;
}
/*
*/
