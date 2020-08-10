#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 3e3 + 5;
struct viet{
        ll dis, x, y;
        bool operator < (const viet &o) const {
                return dis > o.dis;
        }
};
ll a[N][N], b[N][N], dp[N][N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("test.txt", "r", stdin);
        ll m, n;
        cin >> m >> n;
        for (int i = 1; i <= m; i++){
                for (int j = 1; j <= n; j++){
                        dp[i][j] = 1000000000;
                }
        }
        for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++){
                        cin >> a[i][j];
                }
                for (int j = 1; j < n; j++){
                        cin >> b[i][j];
                }
        }
        priority_queue<viet> pq;
        for (int j = 1; j <= n; j++){
                dp[1][j] = a[1][j];
                pq.push({a[1][j], 1, j});
        }
        while (pq.size() > 0){
                viet x = pq.top();
                pq.pop();
                if (x.dis > dp[x.x][x.y]) continue;
                if (x.x > 1) {
                        if (dp[x.x - 1][x.y] > (x.dis + a[x.x][x.y])){
                                dp[x.x - 1][x.y] = x.dis + a[x.x][x.y];
                                pq.push({dp[x.x - 1][x.y], x.x - 1, x.y});
                        }
                }
                if (x.x < m){
                        if (dp[x.x + 1][x.y] > (x.dis + a[x.x + 1][x.y])){
                                dp[x.x + 1][x.y] = x.dis + a[x.x + 1][x.y];
                                pq.push({dp[x.x + 1][x.y], x.x + 1, x.y});
                        }
                }
                if (x.y > 1) {
                        if (dp[x.x][x.y - 1] > (x.dis + b[x.x][x.y - 1])){
                                dp[x.x][x.y - 1] = x.dis + b[x.x][x.y - 1];
                                pq.push({dp[x.x][x.y - 1], x.x, x.y - 1});
                        }
                }
                if (x.y < n){
                        if (dp[x.x][x.y + 1] > (x.dis + b[x.x][x.y])){
                                dp[x.x][x.y + 1] = x.dis + b[x.x][x.y];
                                pq.push({dp[x.x][x.y + 1], x.x, x.y + 1});
                        }
                }
        }
        cout << dp[m][n];
}
/*
*/
