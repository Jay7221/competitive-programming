#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<bool> v(n);
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        v[i] = (a <= q);
    }
    int cur = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(v[i]){
            ++cur;
        }else{
            cur = 0;
        }
        ans += max(0, cur - (k - 1));
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
