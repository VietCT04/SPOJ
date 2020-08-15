#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 3e6 + 5;
ll A, B, D, k;
ll dp[17][12][17][3][2];
vector<ll> a, b;
void dismantle(){
        while (A){
                a.push_back(A % 10);
                A = A / 10;
        }
        while (B){
                b.push_back(B % 10);
                B = B / 10;
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        cin >> A >> B >> D >> k;
        dismantle();
        ll n = b.size();
        memset(dp, -1, sizeof(dp));
        dp[0][0][0][1][0] = 1;
        for (int i = 0; i < n; i++){
                for (int j = 0; j < 10; j++){
                        for (int u = 0; u <= k; u++){
                                for (int x = 0; x < 3; x++){
                                        for (int y = 0; y < 2; y++){
                                                if (dp[i][j][u][x][y] == -1) continue;
                                                for (int nx = 0; nx < 10; nx++){
                                                        ll newx, newy;
                                                        if (x == 1 && nx == b[i]) newx = 1;
                                                        if (x == 2 && nx == b[i]) newx = 2;
                                                        if ((x == 0 && nx == b[i])) newx = 0;
                                                        if (nx > b[i]) newx = 2;
                                                        if (nx < b[i]) newx = 0;
                                                        newy = 1;
                                                        if (dp[i + 1][nx][u + ((max(nx, j) - min(nx, j)) <= D && y)][newx][newy] == -1) dp[i + 1][nx][u + ((max(nx, j) - min(nx, j)) <= D && y)][newx][newy]= 0;
                                                        dp[i + 1][nx][u + ((max(nx, j) - min(nx, j)) <= D && y)][newx][newy] += dp[i][j][u][x][y];
                                                }
                                        }
                                }
                        }
                }
        }
        ll ans = 0;
        for (int f = 1; f < n; f++){
                for (int i = 1; i < 10; i++){
                        for (int j = 0; j <= k; j++){
                                if (dp[f][i][j][0][1] != -1) ans = ans + dp[f][i][j][0][1];
                                if (dp[f][i][j][1][1] != -1) ans = ans + dp[f][i][j][1][1];
                                if (dp[f][i][j][2][1] != -1) ans = ans + dp[f][i][j][2][1];
                        }
                }
        }
        for (int i = 1; i < 10; i++){
                for (int j = 0; j <= k; j++){
                        if (dp[n][i][j][0][1] != -1) ans = ans + dp[n][i][j][0][1];
                }
        }
        memset(dp, -1, sizeof(dp));
        dp[0][0][0][1][0] = 1;
        n = a.size();
        for (int i = 0; i < n; i++){
                for (int j = 0; j < 10; j++){
                        for (int u = 0; u <= k; u++){
                                for (int x = 0; x < 3; x++){
                                        for (int y = 0; y < 2; y++){
                                                if (dp[i][j][u][x][y] == -1) continue;
                                                for (int nx = 0; nx < 10; nx++){
                                                        ll newx, newy;
                                                        if (x == 1 && nx == a[i]) newx = 1;
                                                        if (x == 2 && nx == a[i]) newx = 2;
                                                        if ((x == 0 && nx == a[i])) newx = 0;
                                                        if (nx > a[i]) newx = 2;
                                                        if (nx < a[i]) newx = 0;
                                                        newy = 1;
                                                        if (dp[i + 1][nx][u + ((max(nx, j) - min(nx, j)) <= D && y)][newx][newy] == -1) dp[i + 1][nx][u + ((max(nx, j) - min(nx, j)) <= D && y)][newx][newy]= 0;
                                                        dp[i + 1][nx][u + ((max(nx, j) - min(nx, j)) <= D && y)][newx][newy] += dp[i][j][u][x][y];
                                                }
                                        }
                                }
                        }
                }
        }
        for (int f = 1; f < n; f++){
                for (int i = 1; i < 10; i++){
                        for (int j = 0; j <= k; j++){
                                if (dp[f][i][j][0][1] != -1) ans = ans - dp[f][i][j][0][1];
                                if (dp[f][i][j][1][1] != -1) ans = ans - dp[f][i][j][1][1];
                                if (dp[f][i][j][2][1] != -1) ans = ans - dp[f][i][j][2][1];
                        }
                }
        }
        for (int i = 1; i < 10; i++){
                for (int j = 0; j <= k; j++){
                        if (dp[n][i][j][0][1] != -1) ans = ans - dp[n][i][j][0][1];
                }
        }
        ll cnt = 0;
        for (int i = 1; i < b.size(); i++){
                if ((max(b[i], b[i - 1]) - min(b[i], b[i - 1])) <= D) cnt++;
        }
        cout << ans + (cnt <= k);
}
/*
*/
