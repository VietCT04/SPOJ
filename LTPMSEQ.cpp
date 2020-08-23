#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
map<string, ll> mem;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("help.in", "r")){
                freopen("help.in", "r", stdin);
                freopen("help.out", "w", stdout);
        }
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++){
                string s;
                cin >> s;
                mem[s]++;
        }
        for (auto j : mem){
                if (j.second & 1) cout << j.first;
        }
}
/*
*/
