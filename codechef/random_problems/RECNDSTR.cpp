#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod (ll)(1e9 + 7)
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    if(n == 1){
        cout << "YES\n";
        return ;
    }
    if(n % 2 && (s[0] != s[1])){
        cout << "NO\n";
        return ;
    }
    for(int i = 0; i < n; i++){
        if(s[i] != s[i % 2]){
            cout << "NO\n";
            return ;       
        }
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
     solve();
    }
}