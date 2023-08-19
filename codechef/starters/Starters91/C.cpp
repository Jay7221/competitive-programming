#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, k;
    cin >> n >> k;
    bool flag = true;
    if(n < 2 * k){
        flag = false;
    }else{
        ll p = (n + 1) / 2;
        if((p - k) % 2 == 1){
            flag = false;
        }
    }
    if(flag){
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
