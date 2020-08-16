#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 3e6 + 5;
ll a[200005], b[200005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        ll cnt = 0;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
                ll l = 1, h = cnt;
                while (l <= h){
                        ll mid = (l + h) >> 1;
                        if (a[i] > b[mid]) l = mid + 1;
                        else h = mid - 1;
                }
                if (b[l] == 0) b[l] = a[i];
                else b[l] = min(a[i], b[l]);
                cnt = max(cnt, l);
        }
        cout << cnt;
}
/*
*/
