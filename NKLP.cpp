#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
const int N = 1e5 + 5;
ll a[N], b[N], sum[N];
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
        for (int i = 1; i <= n; i++){
                b[i] = b[i - 1] + a[i] * a[i] + a[i] + 1;
                sum[i] = sum[i - 1] + 1ll * i * i + i + 1;
        }
        bool flag = false;
        ll mx = 1, ans = 0;
        for (int i = 1; i <= n; i++){
                if (a[i] == 1){
                        mx = 1;
                        flag = true;
                }
                if (flag){
                        mx = max(mx, a[i]);
                        if (mx > i) continue;
                        if ((b[i] - b[i - mx]) == sum[mx]){
                                ans = max(ans, mx);
                        }
                }
        }
        memset(b, 0, sizeof(b));
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++){
                b[i] = b[i - 1] + a[i] * a[i] + a[i] + 1;
        }
        flag = false;
        mx = 1;
        for (int i = 1; i <= n; i++){
                if (a[i] == 1){
                        mx = 1;
                        flag = true;
                }
                if (flag){
                        mx = max(mx, a[i]);
                        if (mx > i) continue;
                        if ((b[i] - b[i - mx]) == sum[mx]){
                                ans = max(ans, mx);
                        }
                }
        }
        cout << ans;
}
/*
*/
