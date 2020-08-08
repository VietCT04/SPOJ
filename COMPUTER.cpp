#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 5e5 + 5;
ll x, a, y, b, n;
pair<ll, ll> dp[1005][1005];
bool chk(ll mid){
        for (int i = 0; i <= x; i++){
                for (int j = 0; j <= y; j++){
                        if ((i + j) == 0) continue;
                        pair<ll, ll> use1, use2;
                        use1 = use2 = {0, 0};
                        if (i > 0){
                                use1 = {dp[i - 1][j].first, dp[i - 1][j].second + a};
                                if (use1.second >= mid){
                                        use1 = {dp[i - 1][j].first + 1, 0};
                                }
                        }
                        if (j > 0){
                                use2 = {dp[i][j - 1].first, dp[i][j - 1].second + b};
                                if (use2.second >= mid){
                                        use2 = {dp[i][j - 1].first + 1, 0};
                                }
                        }
                        dp[i][j] = max(use1, use2);
                        if (dp[i][j].first >= n) return true;
                }
        }
        return false;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("A.INP", "r")){
                freopen("A.INP", "r", stdin);
                freopen("A.OUT", "w", stdout);
        }
        cin >> x >> a >> y >> b >> n;
        ll l = 1, h = x * a + b * y;
        while (l <= h){
                ll mid = (l + h) >> 1;
                if (chk(mid)) l = mid + 1;
                else h = mid - 1;
        }
        cout << h << endl;
        cin >> x >> a >> y >> b >> n;
        l = 1, h = x * a + b * y;
        while (l <= h){
                ll mid = (l + h) >> 1;
                if (chk(mid)) l = mid + 1;
                else h = mid - 1;
        }
        cout << h << endl;
}
/*
*/
