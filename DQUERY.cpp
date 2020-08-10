#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int
#define ull unsigned long long
#define endl '\n'
const int N = 305;
ll a[30005], cnt[1000005], ww[200005];
const int block = 100;
struct viet{
        ll l, r, id;
        bool operator <(const viet &o) const{
                return make_pair(l / block, r) < make_pair(o.l / block, o.r);
        }
};
viet qr[200005];
ll ans = 1;
void add(ll id){
        if (cnt[a[id]] == 0) ans++;
        cnt[a[id]]++;
}
void del(ll id){
        if (cnt[a[id]] == 1) ans--;
        cnt[a[id]]--;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("BONUS.INP", "r")){
                freopen("BONUS.INP", "r", stdin);
                freopen("BONUS.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
        }
        ll q;
        cin >> q;
        for (int i = 1; i <= q; i++){
                cin >> qr[i].l >> qr[i].r;
                qr[i].id = i;
        }
        sort(qr + 1, qr + q + 1);
        ll l = qr[1].l, r = qr[1].l;
        cnt[a[qr[1].l]]++;
        for (int i = 1; i <= q; i++){
                while (l > qr[i].l){
                        l--;
                        add(l);
                }
                while (l < qr[i].l){
                        del(l);
                        l++;
                }
                while (r > qr[i].r){
                        del(r);
                        r--;
                }
                while (r < qr[i].r){
                        r++;
                        add(r);
                }
                ww[qr[i].id] = ans;
        }
        for (int i = 1; i <= q; i++) cout << ww[i] << endl;
}
/*
*/ 
