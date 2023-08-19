#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i];
    }

    auto overlap = [&](int l1, int r1, int l2, int r2){
        if((l1 <= l2) && (l2 <= r1)){
            return true;
        }
        if((l1 <= r2) && (r2 <= r1)){
            return true;
        }
        if((l2 <= l1) && (r1 <= r2)){
            return true;
        }
        return false;
    };

    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(overlap(l[i], r[i], l[j], r[j])){
                int L = min(l[i],  l[j]);
                int R = max(r[i], r[j]);
                v.push_back({R, L});
            }
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int cur = -1;
    for(auto [r, l] : v){
        if(cur < l){
            cur = r;
            ++ans;
        }
    }
    ans = n - 2 * ans;
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
