#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
bool isp[1000005];
ll lim = 1e6;
vector<ll> ans;
ll CntInt(ll x){
        ll res = 0;
        while (x > 0){
                res++;
                x = x / 10;
        }
        return res;
}
void add(ll x){
        ll p = 1;
        ll n = CntInt(x);
        for (int i = 1; i < n; i++){
                p = p * 10;
        }
        for (int i = 1; i <= n; i++){
                ans.push_back(x / p);
                x = x - x / p * p;
                p = p / 10;
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n, k;
        cin >> n >> k;
        memset(isp, 1, sizeof(isp));
        for (int i = 2; i * i <= lim; i++){
                if (isp[i]){
                        for (int j = i * i; j <= lim; j += i){
                                isp[j] = 0;
                        }
                }
        }
        for (int i = 2; i <= 1000000; i++){
                if (isp[i]){
                        n--;
                        add(i);
                        if (n == 0) break;
                }
        }
        vector<ll> res;
        res.push_back(ans[0]);
        for (int i = 1; i < ans.size(); i++){
                while (ans[i] > res.back() && k){
                        k--;
                        res.pop_back();
                        if (res.size() == 0) break;
                }
                res.push_back(ans[i]);
        }
        while (k){
                k--;
                res.pop_back();
        }
        for (auto j : res) cout << j;
}
/*
*/
