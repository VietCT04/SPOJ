#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
ll a[505][505], col[505][505], row[505][505], dp[505][505];
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
                ll n;
                cin >> n;
                for (int i = 1; i <= n; i++){
                        for (int j = 1; j <= n; j++){
                                cin >> a[i][j];
                                col[i][j] = col[i - 1][j] + a[i][j];
                                row[i][j] = row[i][j - 1] + a[i][j];
                        }
                }
                for (int i = 1; i <= n; i++){
                        for (int j = 1; j <= n; j++){
                                dp[i][j] = 0;
                                if (((col[i][j] % 2) == 0) && dp[i][j - 1] == 0) dp[i][j] = 1;
                                if (((row[i][j] % 2) == 0) && dp[i - 1][j] == 0) dp[i][j] = 1;
                        }
                }
                if (dp[n][n]) cout << "YES" << endl;
                else cout << "NO" << endl;
        }
}
/*
*/
