#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0;
    int ans = 1;
    char prev = '$';
    for(char si : s){
        if(si == prev){
            ++cur;
        }else{
            cur = 1;
            prev = si;
        }
        ans = max(ans, cur + 1);
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
