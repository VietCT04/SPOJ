#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
ll a[5][10005], dp[10005][20];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        ll ans = -1e18;
        for (int i = 1; i <= 4; i++){
                for (int j = 1; j <= n; j++){
                        cin >> a[i][j];
                        ans = max(ans, a[i][j]);
                }
        }
        ll maxbit = (1 << 4) - 1;
        for (int i = 1; i <= n; i++){
                for (int j = 0; j < (1 << 4); j++){
                        ll last = -69;
                        bool flag = true;
                        ll sum = 0;
                        for (int k = 0; k < 4; k++){
                                if (j & (1 << k)){
                                        if ((k - last) == 1) flag = false;
                                        last = k;
                                        sum = sum + a[k + 1][i];
                                }
                        }
                        if (flag) dp[i][j] = max(dp[i][j], dp[i - 1][maxbit ^ j] + sum);
                }
                for (int j = 0; j < (1 << 4); j++){
                        for (int k = 0; k < 4; k++){
                                if (j & (1 << k)){
                                        dp[i][j] = max(dp[i][j], dp[i][j ^ (1 << k)]);
                                }
                        }
                }
        }
        if (ans > 0) cout << dp[n][maxbit];
        else cout << ans;   
}
/*
*/
