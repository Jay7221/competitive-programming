#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    map<int, bool> vis;
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(vis[v[i]]){
            if(v[i - 1] != v[i]){
                cout << "IMPOSSIBLE\n";
                return;
            }
            continue;
        }
        ans.push_back(v[i]);
        vis[v[i]] = true;
    }
    for(int elem : ans){
        cout << elem << ' ';
    }
    cout << '\n';
}
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
