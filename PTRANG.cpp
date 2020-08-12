#include <bits/stdc++.h>

using namespace std;

#define ll int
#define ull unsigned long long
#define endl '\n'
const int N = 4e5 + 5;
ll a[N], dp[N], sum[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("tests.in", "r")){
                freopen("tests.in", "r", stdin);
                //freopen("BONUS.OUT", "w", stdout);
        }
        ll n, L;
        cin >> n >> L;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
                sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++){
                dp[i] = 1e9;
                for (int j = 1; j <= i; j++){
                        if ((sum[i] - sum[j - 1]) <= L){
                                dp[i] = min(dp[i], max(dp[j - 1], L - sum[i] + sum[j - 1]));
                        }
                }
        }
        cout << dp[n];
}
/*
*/
