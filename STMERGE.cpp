#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
ll a[1005][1005], dp[1005][1005][2];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll t;
        cin >> t;
        while (t--){
                ll n, m;
                cin >> n >> m;
                for (int i = 1; i <= n; i++){
                        for (int j = 1; j <= m; j++){
                                cin >> a[i][j];
                        }
                }
                dp[0][0][1] = 0;
                dp[0][0][1] = 0;
                for (int i = 0; i <= n; i++){
                        for (int j = 0; j <= m; j++){
                                if (i == 0 && j == 0) continue;
                                dp[i][j][0] = 1e18;
                                dp[i][j][1] = 1e18;
                                if (i > 0){
                                        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
                                        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + a[i][j]);
                                }
                                if (j > 0){
                                        dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1]);
                                        dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + a[i][j]);
                                }
                        }
                }
                cout << min(dp[n][m][0], dp[n][m][1]) << endl;
        }
}
/*
*/
