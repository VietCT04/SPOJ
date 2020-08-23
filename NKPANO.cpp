#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
struct viet{
        ll l, p, s;
        bool operator <(const viet& o) const{
                return s < o.s;
        }
}a[105];
ll dp[16005];
ll cnt[10005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++){
                cin >> a[i].l >> a[i].p >> a[i].s;
        }
        sort(a + 1, a + k + 1);
        a[0].s = 0;
        a[k + 1].s = n + 1;
        for (int i = 1; i <= k; i++){
                memset(cnt, 0, sizeof(cnt));
                for (int j = a[i - 1].s + 1; j <= a[i].s; j++) dp[j] = max(dp[j], dp[j - 1]);
                for (int j = max(a[i].s - a[i].l + 1, 1ll); j <= a[i].s; j++){
                        cnt[a[i].l - (a[i].s - j + 1)] = dp[j - 1] + a[i].p * (a[i].s - j + 1);
                        dp[a[i].s] = max(dp[a[i].s], dp[j - 1] + a[i].p * (a[i].s - j + 1));
                }
                for (int j = a[i].l; j >= 0; j--){
                        cnt[j] = max(cnt[j], cnt[j + 1]);
                }
                for (int j = a[i].s + 1; j <= min(a[i].s + a[i].l - 1, n); j++){
                        dp[j] = max(dp[j], cnt[j - a[i].s] + (j - a[i].s) * a[i].p);
                }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                ans = max(ans, dp[i]);
        }
        cout << ans;
}
/*
*/
