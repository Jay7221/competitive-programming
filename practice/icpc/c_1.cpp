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
    sort(v.begin(), v.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ans = 0;
    for(auto [l, r]: v){
        if(l == 1){
            continue;
        }
        pq.push({r, l});
        while(pq.top().first < l){
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    while(!pq.empty()){
        pq.pop();
    }
    for(auto [l, r]: v){
        if(r == m){
            continue;
        }
        pq.push({r, l});
        while(pq.top().first < l){
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
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
