#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
ll l[30005], r[30005], a[30005];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll t;
        cin >> t;
        while (t--){
                ll n;
                cin >> n;
                for (int i = 1; i <= n; i++) cin >> a[i];
                stack<ll> s;
                for (int i = 1; i <= n; i++){
                        while (s.size()){
                                if (a[i] <= a[s.top()]){
                                        s.pop();
                                } else break;
                        }
                        if (s.size()) l[i] = s.top() + 1;
                        else l[i] = 1;
                        s.push(i);
                }
                while (s.size()) s.pop();
                for (int i = n; i >= 1; i--){
                        while (s.size()){
                                if (a[i] <= a[s.top()]) s.pop();
                                else break;
                        }
                        if (s.size()) r[i] = s.top() - 1;
                        else r[i] = n;
                        s.push(i);
                }
                ll ans = -1, curl, curr;
                for (int i = 1; i <= n; i++){
                        ll cost = (r[i] - l[i] + 1) * a[i];
                        if (cost == ans && l[i] < curl){
                                curl = l[i];
                                curr = r[i];
                        }
                        if (cost > ans){
                                ans = cost;
                                curl = l[i];
                                curr = r[i];
                        }
                }
                cout << ans << " " << curl << " " << curr << endl;
        }
}
/*
*/
