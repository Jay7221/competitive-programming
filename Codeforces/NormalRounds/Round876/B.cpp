#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    ll ans = 0;
    for(int k = 1; k <= n; ++k){
        sort(v[k].rbegin(), v[k].rend());
        for(int i = 0; i < min((int)v[k].size(), k); ++i){
            ans += v[k][i];
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
