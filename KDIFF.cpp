#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define endl '\n'
#define ll int
const int N = 3e5 + 5;
ll dpx[N][20], dpn[N][20], f[N], a[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("haircut.in", "r", stdin);
        //freopen("haircut.out", "w", stdout);
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
                dpn[i][0] = a[i];
                dpx[i][0] = a[i];
        }
        for (int j = 1; j < 20; j++){
                for (int i = 1; (i + (1ll << j) - 1) <= n; i++){
                        dpx[i][j] = max(dpx[i][j - 1], dpx[i + (1ll << (j - 1))][j - 1]);
                        dpn[i][j] = min(dpn[i][j - 1], dpn[i + (1ll << (j - 1))][j - 1]);
                }
        }
        f[0] = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                ll l = 1, h = i;
                while (l <= h){
                        ll mid = (l + h) >> 1;
                        ll j = (ll)(log2(i - mid + 1));
                        ll minimum = min(dpn[mid][j], dpn[i - (1ll << j) + 1][j]);
                        ll maximum = max(dpx[mid][j], dpx[i - (1ll << j) + 1][j]);
                        ll ok = maximum - minimum;
                        if (ok > k) l = mid + 1;
                        else h = mid - 1;
                }
                f[i] = max(f[i - 1], i - l + 1);
                ans = max(ans, i - l + 1 + f[l - 1]);
        }
        cout << ans;
}
/*
*/
