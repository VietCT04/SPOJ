#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 3e6 + 5;
ll lcs[5005], a[5005], b[5005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        ll ans = 0;
        memset(lcs, -1, sizeof(lcs));
        for (int i = 1; i <= n; i++){
                ll mx = 0;
                for (int j = 1; j <= m; j++){
                        ll pre = mx;
                        if (lcs[j] != -1) mx = max(mx, lcs[j] + abs(a[i] - b[j]));
                        if (a[i] == b[j]) lcs[j] = max(lcs[j], pre);
                        ans = max(ans, lcs[j]);
                }
        }
        cout << ans;
}
/*
*/
