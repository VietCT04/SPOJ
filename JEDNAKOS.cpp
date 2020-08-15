#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 3e6 + 5;
ll dp[2005][5005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        string s;
        cin >> s;
        ll n = s.length(), sig;
        s = ' ' + s;
        for (int i = 0; i <= n; i++){
                for (int j = 0; j <= 5000; j++){
                        dp[i][j] = 1e9;
                }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++){
                if (s[i] == '='){
                        sig = i;
                        break;
                }
                if (s[i] == '0'){
                        for (int j = 0; j <= 5000; j++){
                                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (s[i + 1] == '='));
                        }
                } else {
                        for (int j = 0; j <= 5000; j++){
                                if (dp[i - 1][j] == 1e9) continue;
                                ll p = 0;
                                for (int k = i; k <= n; k++){
                                        if (s[k] == '=') break;
                                        p = p * 10 + (s[k] - '0');
                                        if ((p + j) > 5000) break;
                                        dp[k][p + j] = min(dp[k][p + j], dp[i - 1][j] + 1);
                                }
                        }
                }
        }
        ll p = 0;
        for (int i = sig + 1; i <= n; i++){
                p = p * 10 + (s[i] - '0');
        }
        cout << dp[sig - 1][p] - 1;
}
/*
*/
