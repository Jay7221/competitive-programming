#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll m, n;
    cin >> m >> n;
    bool ans;
    if(m < n){
        ans = false;
    }else{
        while(m % 2 == 0){
            m /= 2;
        }
        if(n % m == 0){
            ans = true;
        }else{
            ans = false;
        }
    }
    if(ans){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
