#include <bits/stdc++.h>
 
using namespace std;

#define ll long long
const int MAX = 1e5 + 7;
const int LOGMAX = 20;
vector<vector<int>> cnt(LOGMAX, vector<int>(MAX));
void pre(){
    for(int x = 0; x < LOGMAX; ++x){
        for(int i = 1; i < MAX; ++i){
            cnt[x][i] = cnt[x][i - 1] + (1 & (i >> x));
        }
    }
}
void solve() {
    int l, r, x;
    cin >> l >> r >> x;
    --x;
    cout << (cnt[x][r] - cnt[x][l - 1]) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
