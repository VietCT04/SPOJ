#include <bits/stdc++.h>

using namespace std;

#define ll int
#define ull unsigned long long
#define endl '\n'
const int N = 2e5 + 5;
ll dp[305][305], a[305];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("tests.in", "r")){
                freopen("tests.in", "r", stdin);
                //freopen("BONUS.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll ans = 0;
        for (int i = 2; i <= n; i++){ // start
                for (int x = 1; x < i; x++){
                        for (int y = i; y <= n; y++){
                                if (x == 1 && y == i) dp[x][y] = 0;
                                else {
                                        dp[x][y] = 0;
                                        if (x > 0) dp[x][y] = max(dp[x][y], dp[x - 1][y]);
                                        if (y > i) dp[x][y] = max(dp[x][y], dp[x][y - 1]);
                                }
                                if (a[x] >= a[y]) continue;
                                if (x > 1 && y > i) dp[x][y] = max(dp[x][y], dp[x - 1][y - 1] + 1);
                                else dp[x][y] = 1;
                                ans = max(ans, dp[x][y]);
                        }
                }
        }
        cout << ans;
}
/*
*/
