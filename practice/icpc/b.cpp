#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; 
    cin >> n;
    string s; cin >> s;
    string t; cin >> t;
    int z1 = 0, z2 = 0;
    for(int i = 0; i < n; ++i){
        z1 += (s[i] == '0');
        z2+= (t[i] == '0');
    }
    if(z1 == n && z2 == n) cout << "YES\n";
    else if(z1 == n || z2 == n) cout << "NO\n";
    else{
        if(n % 2 == 0) cout << "YES\n";
        else{
            int c1 = 0, c2 = 0;
            for(int i = 0; i < n; i+=2){
                c1 += (s[i] == '0');
                c2 += (t[i] == '0');
            }
            if(c1 % 2 == c2 % 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
