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
const int base = 311;
ll pows[maxx];
ll hashP[maxx];
ll hashT = 0;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen(".INP","r",stdin);
        //freopen(".OUT","w",stdout);
        string s, t;
        cin >> s >> t;
        ll n = s.length(), m = t.length();
        s = " " + s;
        t = " " + t;
        pows[0] = 1;
        for (int i = 1; i <= n; i++){
                pows[i] = (pows[i - 1] * base)%mod;
        }
        for (int i = 1; i <= m; i++){
                hashT = (hashT * base + (t[i] - 'a' + 1))%mod;
        }
        for (int i = 1; i <= n; i++){
                hashP[i] = (hashP[i - 1] * base + (s[i] - 'a' + 1))%mod;
        }
        for (int i = 1; i <= n - m + 1; i++){
                if ((hashP[i + m - 1] - hashP[i - 1]*pows[m] + mod*mod)%mod == hashT){
                        cout << i << " ";
                }
        }
}
