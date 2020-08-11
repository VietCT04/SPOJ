#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define pb push_back
#define endl '\n'
#define ff first
#define mp make_pair
#define ss second
#define YES cout << "YES"<<endl;
#define NO cout << "NO"<<endl;
using namespace std;
ll maxn = -1e18;
ll minn = 1e18;
ll mod = 1e9 + 7;
const int maxx = 1e6 + 5;
const int base = 31;
ll pows[maxx];
ll hashs[maxx];
ll hashp[maxx];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen(".INP","r",stdin);
        //freopen(".OUT","w",stdout);
        ll n, m;
        cin >> n >> m;
        string s, p;
        cin >> s >> p;
        s = " " + s;
        p = " " + p;
        pows[0] = 1;
        ll q;
        cin >> q;
        for (int i = 1; i <= n; i++){
                pows[i] = (pows[i - 1] * base)%mod;
        }
        for (int i = 1; i <= n; i++){
                hashs[i] = (hashs[i - 1] * base + (s[i] - 'a' + 1))%mod;
        }
        for (int i = 1; i <= m; i++){
                hashp[i] = (hashp[i - 1] * base + (p[i] - 'a' + 1))%mod;
        }
        for (int z = 1; z <= q; z++){
                ll x, y, u, v;
                cin >> x >> y >> u >> v;
                ll l = 0, h = min(y - x + 1, v - u + 1);
                while (l <= h){
                        ll mid = (l + h)/2;
                        bool flag = false;
                        if ((hashs[mid + x - 1] - hashs[x - 1]*pows[mid] + mod*mod)%mod == ((hashp[mid + u - 1] - hashp[u - 1]*pows[mid] + mod*mod)%mod)){
                                flag = true;
                        }
                        if (flag) l = mid + 1;
                        else h = mid - 1;
                }
                if (h == min(y - x + 1, v - u + 1)){
                        if ((y - x + 1) == (v - u + 1))cout << "=";
                        else if (y - x + 1 > v - u + 1)cout << ">";
                        else cout << "<";
                }
                else {
                        if (s[x + h] > p[u + h])cout << ">";
                        else cout << "<";
                }
        }
}
 
