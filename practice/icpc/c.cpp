#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i){
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    int ans = 0;
    int cur;
    vector<pair<int, int>> arr;

    for(auto [l, r]: v){
        if(l != 1){
            arr.push_back({l, 1});
            arr.push_back({r + 1, -1});
        }
    }
    sort(arr.begin(), arr.end());
    cur = 0;
    for(auto [ind, val]: arr){
        cur += val;
        ans = max(ans, cur);
    }

    cur = 0;
    arr.clear();

    for(auto [l, r]: v){
        if(r != m){
            arr.push_back({l, 1});
            arr.push_back({r + 1, -1});
        }
    }
    sort(arr.begin(), arr.end());
    cur = 0;
    for(auto [ind, val]: arr){
        cur += val;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
