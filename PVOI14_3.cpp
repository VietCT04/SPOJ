// code 100đ trên cf, 95đ spoj
#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 1e6 + 5;
long double eps = 1e-3;
long double d[1005];
ll u[10005], v[10005], c[10005], par[1005];
bool Ok(int x, int y) {
    while (x != 1){
        x = par[x];
        if (x == 0) return false;
        if (x == y) return true;
    }
    return false;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("test.txt", "r")){
                freopen("test.txt", "r", stdin);
                //freopen("test.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
                cin >> u[i] >> v[i] >> c[i];
        }
        long double l = 1, h = 1e10;
        while ((h - l) > eps){
                long double mid = (l + h) / 2;
                for (int i = 1; i <= n; i++) d[i] = 0;
                for (int i = 1; i <= n; i++) par[i] = -1;
                ll x = -1;
                for (int i = 1; i <= n; i++){
                        x = -1;
                        for (int j = 1; j <= m; j++){
                                if (d[v[j]] > (d[u[j]] + c[j] - mid)){
                                        d[v[j]] = d[u[j]] + c[j] - mid;
                                        if (Ok(u[j], v[j])){
                                                x = 156;
                                                break;
                                        }
                                        par[v[j]] = u[j];
                                        x = v[j];
                                }
                        }
                        if (x == 156) break;
                }
                if (x == -1) l = mid + eps;
                else h = mid - eps;
        }
        if (l > 1e9) cout << "NO TOUR";
        else cout << fixed << setprecision(2) << h;
}
/*
*/
