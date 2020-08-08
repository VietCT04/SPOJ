#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int
#define endl '\n'
const int N = 5e5 + 5;
ll a[1005], dp[1005][1005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("A.INP", "r")){
                freopen("A.INP", "r", stdin);
                freopen("A.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll cnt = 0;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++){
                for (int j = 0; j <= (cnt + 1); j++){
                        dp[i][j] = 1e9;
                        if (j < cnt) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                        if (a[i] > 100 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i]);
                        else dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
                }
                if (a[i] > 100) cnt++;
        }
        ll ans = 1e9;
        for (int i = 0; i <= cnt; i++) ans = min(ans, dp[n][i]);
        cout << ans;
}
/*
*/
