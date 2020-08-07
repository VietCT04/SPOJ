#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
ll lab[N];
struct viet{
        ll x, y, z, id;
}a[N];
struct node{
        ll u, v, c;
        bool operator <(const node &o) const{
                return c < o.c;
        }
};
ll find_set(ll u){
        if (lab[u] < 0) return u;
        return lab[u] = find_set(lab[u]);
}
bool dsu(ll u, ll v){
        u = find_set(u);
        v = find_set(v);
        if (u == v) return 0;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return 1;
}
bool xx(viet x, viet y){
        return x.x < y.x;
}
bool yy(viet x, viet y){
        return x.y < y.y;
}
bool zz(viet x, viet y){
        return x.z < y.z;
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
        memset(lab, -1, sizeof(lab));
        for (int i = 1; i <= n; i++){
                cin >> a[i].x >> a[i].y >> a[i].z;
                a[i].id = i;
        }
        vector<node> q;
        sort(a + 1, a + n + 1, xx);
        for (int i = 2; i <= n; i++) q.push_back({a[i].id, a[i - 1].id, a[i].x - a[i - 1].x});
        sort(a + 1, a + n + 1, yy);
        for (int i = 2; i <= n; i++) q.push_back({a[i].id, a[i - 1].id, a[i].y - a[i - 1].y});
        sort(a + 1, a + n + 1, zz);
        for (int i = 2; i <= n; i++) q.push_back({a[i].id, a[i - 1].id, a[i].z - a[i - 1].z});
        sort(q.begin(), q.end());
        ll ans = 0;
        for (auto j : q){
                if (dsu(j.u, j.v)) ans += j.c;
        }
        cout << ans;
}
/*
*/
