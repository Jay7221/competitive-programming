#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i){
        v.push_back({h[i], h[i] - a[i]});
    }
    int cur = 0;
    sort(v.begin(), v.end());
    int ans = 0;
    for(auto [r, l]: v){
        if(l >= cur){
            cur = r;
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
 
