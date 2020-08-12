#include <bits/stdc++.h>

using namespace std;

#define ll int
#define ull unsigned long long
#define endl '\n'
const int N = 1e3 + 5;
bool dp[21][21][205];
ll a[21][21];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("tests.in", "r")){
                freopen("tests.in", "r", stdin);
                //freopen("BONUS.OUT", "w", stdout);
        }
        ll S, k, n;
        cin >> S >> k >> n;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= k; j++){
                        cin >> a[i][j];
                }
        }
        for (int i = 1; i <= n; i++){
                if (a[i][1] <= S) dp[1][i][a[i][1]] = 1;
        }
        for (int i = 1; i < k; i++){ // bai
                for (int j = 1; j <= n; j++){ // giam thi cua bai nay
                        for (int f = 0; f <= S; f++){ // diem hien tai]
                        if (dp[i][j][f] == 0) continue;
                                for (int t = 1; t <= n; t++){ // giam thi cua bai tiep theo
                                        if (a[t][i + 1] < a[j][i]) continue;
                                        if ((f + a[t][i + 1]) <= S) dp[i + 1][t][f + a[t][i + 1]] = 1;
                                }
                        }
                }
        }
        bool flag = false;
        ll i = k, j;
        for (int i = 1; i <= n; i++){
                if (dp[k][i][S]){
                        flag = true;
                        j = i;
                }
        }
        if (!flag) cout << "NO" << endl;
        else {
                vector<ll> ans;
                cout << "YES" << endl;
                while (true){
                        ans.push_back(a[j][i]);
                        if (i == 1) break;
                        for (int t = 1; t <= n; t++){
                                if (a[j][i] >= a[t][i - 1] && dp[i - 1][t][S - a[j][i]]){
                                        S = S - a[j][i];
                                        i--;
                                        j = t;
                                        break;
                                }
                        }
                }
                reverse(ans.begin(), ans.end());
                for (auto t : ans) cout << t << " ";
        }
}
/*
*/
