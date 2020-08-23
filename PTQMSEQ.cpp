#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
ll a[2000005], sum[3000010];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("help.in", "r")){
                freopen("help.in", "r", stdin);
                freopen("help.out", "w", stdout);
        }
        ll n;
        cin >> n;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
        for (int i = n + 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i - n];
        pq.push({0, 0});
        ll ans = -1e18;
        for (int i = 1; i <= 2 * n; i++){
                while (pq.size()){
                        if ((i - pq.top().second) >= n) pq.pop();
                        else break;
                }
                ans = max(ans, sum[i] - pq.top().first);
                pq.push({sum[i], i});
        }
        cout << ans;
}
/*
*/
