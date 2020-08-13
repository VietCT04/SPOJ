#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
bool f[1005][1005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        string s;
        cin >> s;
        ll n = s.length();
        s = " " + s;
        for (int i = 2; i <= n; i++){
                for (int l = 1; (l + i - 1) <= n; l++){
                        f[l][l + i - 1] = (s[l] == s[l + i - 1] && (i <= 3 || f[l + 1][l + i - 2]));
                }
        }
        for (int i = n; i >= 1; i--){
                for (int j = i + 2; j <= n; j++){
                        for (int p = i + 1; !f[i][j] && (p + 1) < j; p++){
                                f[i][j] |= (f[i][p] && f[p + 1][j]);
                        }
                }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j < i; j++){
                        ans += f[j][i];
                }
        }
        cout << ans;
}
/*
*/
