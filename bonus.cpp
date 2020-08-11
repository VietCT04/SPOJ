#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 305;
ll a[N];
ll n, k;
ll dp[N][N][155];
ll DP(ll l, ll r, ll t){
        if (l > r) {
                if (t > k) return 0;
                else return -1e9;
        }
        if (dp[l][r][t] != -1) return dp[l][r][t];
        dp[l][r][t] = 0;
        if ((r - l + 1) >= 2){
                if (t <= k){
                        dp[l][r][t] = max(dp[l][r][t], DP(l + 1, r - 1, t + 1) + abs(a[l] - a[r]));
                        dp[l][r][t] = max(dp[l][r][t], DP(l + 2, r, t + 1) + abs(a[l] - a[l + 1]));
                        dp[l][r][t] = max(dp[l][r][t], DP(l, r - 2, t + 1) + abs(a[r] - a[r - 1]));
                }
        }
        if ((r - l + 1) >= 1){
                dp[l][r][t] = max(dp[l][r][t], DP(l, r - 1, t));
                dp[l][r][t] = max(dp[l][r][t], DP(l + 1, r, t));
        }
        return dp[l][r][t];
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("BONUS.INP", "r")){
                freopen("BONUS.INP", "r", stdin);
                freopen("BONUS.OUT", "w", stdout);
        }
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        cout << DP(1, n, 1);
}
/*
*/
