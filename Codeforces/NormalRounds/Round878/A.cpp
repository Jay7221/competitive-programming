#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(s[i] == s[j]){
                ans.push_back(s[i]);
                i = j;
                break;
            }
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
