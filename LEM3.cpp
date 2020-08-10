#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
ll c[18][18], dp[100005][18];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                        cin >> c[i][j];
                }
        }
        for (int i = 1; i < (1 << n); i++){
                for (int j = 1; j <= n; j++){
                        dp[i][j] = 1e9;
                }
        }
        for (int i = 0; i < n; i++) dp[1 << i][i + 1] = 0;
        for (int i = 1; i < (1 << n); i++){
                for (int j = 0; j < n; j++){
                        if (dp[i][j + 1] == 1e9) continue;
                        for (int k = 0; k < n; k++){
                                if (!(i & (1 << k)) && (i & (1 << j))){
                                        dp[i | (1 << k)][k + 1] = min(dp[i | (1 << k)][k + 1], dp[i][j + 1] + c[j + 1][k + 1]);
                                }
                        }
                }
        }
        ll ans = 1e9;
        for (int i = 1; i <= n; i++){
                ans = min(ans, dp[(1 << n) - 1][i]);
        }
        cout << ans;
}
/*
*/
