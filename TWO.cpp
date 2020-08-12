#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
const int N = 2e5 + 5;
ll a[N], b[N];
bool cmp1(ll x, ll y){
        return a[x] < a[y];
}
bool cmp2(ll x, ll y){
        return b[x] > b[y];
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
                cin >> b[i];
        }
        vector<ll> f1, f2;
        for (int i = 1; i <= n; i++){
                if (a[i] <= b[i]) f1.push_back(i);
                else f2.push_back(i);
        }
        sort(f1.begin(), f1.end(), cmp1);
        sort(f2.begin(), f2.end(), cmp2);
        ll t1 = 0;
        ll t2 = 0;
        for (auto j : f1){
                t1 = t1 + a[j];
                t2 = max(t2, t1) + b[j];
        }
        for (auto j : f2){
                t1 = t1 + a[j];
                t2 = max(t2, t1) + b[j];
        }
        cout << t2 << endl;
        for (auto j : f1) cout << j << " ";
        for (auto j : f2) cout << j << " ";
}
/*
*/
 
