#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int
#define endl '\n'
const int N = 2e5 + 5;
char c[5005][5005];
ll dp[5005][5005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                        cin >> c[i][j];
                }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                        if (c[i][j] == '1') dp[i][j] = 0;
                        else {
                                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                                ans += dp[i][j];
                        }
                }
        }
        cout << ans;
}
/*
*/
