#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    ll lsb = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        lsb |= a[i];
    }
    for(int k = 0; k < 63; ++k){
        if((lsb >> k) != 0){
            lsb = ((lsb >> k) << k);
        }
    }
    int cnt = 0;
    for(ll elem : a){
        if((lsb & elem) > 0){
            ++cnt;
        }
    }
    cout << ((cnt + 1) / 2) << '\n';
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
