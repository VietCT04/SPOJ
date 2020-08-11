#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("test.txt", "r")){
                freopen("test.txt", "r", stdin);
                //freopen("test.OUT", "w", stdout);
        }
        ll n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        ll ans = 1000000;
        for (int i = 1; i <= k; i++){
                string t;
                cin >> t;
                for (int j = 0; j < n; j++){
                        ll res = 0;
                        ll x = j;
                        for (int y = 0; y < m; y++){
                                res = res + (t[y] != s[x]);
                                x++;
                                if (x >= n) x = 0;
                        }
                        ans = min(ans, res);
                }
        }
        cout << ans;
}
/*
*/
