#include <bits/stdc++.h>

using namespace std;

#define ll int
#define endl '\n'
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
string s[1005], t[105];
set<ll> st[28];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
                cin >> s[i];
                for (int j = 0; j < s[i].length(); j++){
                        if (s[i][j] >= 'A' && s[i][j] <= 'Z'){
                                s[i][j] = char('a' + (s[i][j] - 'A'));
                        }
                }
        }
        for (int i = 1; i <= m; i++){
                cin >> t[i];
                for (int j = 0; j < t[i].length(); j++){
                        if (t[i][j] >= 'A' && t[i][j] <= 'Z'){
                                t[i][j] = char('a' + (t[i][j] - 'A'));
                        }
                }
        }
        for (int i = 1; i <= n; i++){
                for (int j = 0; j < 26; j++) st[j].clear();
                for (int j = 0; j < s[i].length(); j++){
                        st[s[i][j] - 'a'].insert(j);
                }
                ll cnt = 0;
                for (int j = 1; j <= m; j++){
                        ll now = 0;
                        bool flag = true;
                        for (int k = 0; k < t[j].length(); k++){
                                auto it = st[t[j][k] - 'a'].lower_bound(now);
                                if (it == st[t[j][k] - 'a'].end()){
                                        flag = false;
                                        break;
                                }
                                now = (*it) + 1;
                        }
                        cnt += flag;
                }
                cout << cnt << endl;
        }
}
/*
*/
