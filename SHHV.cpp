#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
ll a[20], fact[20], vis[20];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("test.txt", "r")){
                freopen("test.txt", "r", stdin);
                //freopen("test.OUT", "w", stdout);
        }
        ll x;
        ll n = 0;
        while (cin >> x) {
                n++;
                a[n] = x;
        }
        n--;
        ll k = a[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                        if (!vis[j] && j < a[i]){
                                ans = ans + fact[n - i];
                        }
                }
                vis[a[i]] = 1;
        }
        cout << ans + 1 << endl;
        memset(vis, 0, sizeof(vis));
        k--;
        for (int i = 1; i <= n; i++){
                ll index = k / fact[n - i];
                for (int j = 1; j <= n; j++){
                        if (index == 0 && !vis[j]){
                                cout << j << " ";
                                vis[j] = 1;
                                break;
                        }
                        if (!vis[j]) index--;
                }
                k = k % fact[n - i];
        }
}
/*
*/
