#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m;
    cin >> n >> m;
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        sum1 += a;
    }
    for(int i = 0; i < m; ++i){
        ll b;
        cin >> b;
        sum2 += b;
    }
    if(sum1 > sum2){
        cout << "Tsondu\n";
    }else if(sum1 == sum2){
        cout << "Draw\n";
    }else{
        cout << "Tenzing\n";
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
