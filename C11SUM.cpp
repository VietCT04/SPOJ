#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 3e6 + 5;
ll sum[1000006];
ll mod = 1e9 + 7;
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
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + 1;
        ll ans = 0, p = 0;
        for (int i = n; i >= 1; i--){
                p = (p * 10 + 1) % mod;
                ans = (ans + sum[i] * (s[i] - '0') * p) % mod;
        }
        cout << ans;
}
/*
*/
