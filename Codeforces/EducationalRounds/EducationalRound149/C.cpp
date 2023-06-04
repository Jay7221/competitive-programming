#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(s[n - 1] == '?'){
        s[n - 1] = '1';
    }
    for(int i = n - 2; i >= 0; --i){
        if(s[i] == '?'){
            s[i] = s[i + 1];
        }
    }
    cout << s << '\n';
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
