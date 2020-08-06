#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
ll f[N], sum[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n, s, mod;
        cin >> n >> mod >> s;
        f[1] = 1;
        f[2] = 2;
        if (mod == 1){
                cout << 0;
                return 0;
        }
        if (mod == 2){
                if (s > n / 2) cout << 1;
                else cout << 0;
                return 0;
        }
        ll period;
        for (int i = 3;; i++){
                f[i] = (f[i - 1] + f[i - 2]) % mod;
                if (f[i - 1] == 1 && f[i] == 2){
                        period = i - 2;
                        break;
                }
        }
        ll tm = n / period, remain = n % period;
        for (int i = 1; i <= period; i++) sum[f[i]] += tm;
        for (int i = 1; i <= remain; i++) sum[f[i]] += 1;
        ll cur = 0;
        for (int i = 0; i < mod; i++){
                cur = cur + sum[i];
                if (cur >= s){
                        cout << i;
                        return 0;
                }
        }
}
/*
*/
