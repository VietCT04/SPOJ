#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
ll sum[N], a[N], dp[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        dp[0] = 0;
        deque<ll> q;
        multiset<ll> s;
        ll l = 0;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
                if (a[i] > m){
                        return cout << -1, 0;
                }
                sum[i] = sum[i - 1] + a[i];
                while ((sum[i] - sum[l]) > m) l++;
                bool flag = false;
                while (q.size()){
                        if (q.front() < l){
                                ll x = q.front();
                                q.pop_front();
                                if (q.size()) s.erase(s.lower_bound(dp[x] + a[q.front()]));
                                flag = true;
                        }
                        else break;
                }
                if (flag && q.size()){
                        s.insert(dp[l] + a[q.front()]);
                        q.push_front(l);
                }
                while (q.size()){
                        if (a[i] >= a[q.back()]){
                                ll x = q.back();
                                q.pop_back();
                                if (q.size()) s.erase(s.lower_bound(dp[q.back()] + a[x]));
                        } else {
                                break;
                        }
                }
                if (q.size() == 0) q.push_back(l);
                s.insert(dp[q.back()] + a[i]);
                q.push_back(i);
                dp[i] = *s.begin();
        }
        cout << dp[n];
}
/*
*/
