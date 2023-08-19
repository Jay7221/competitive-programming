#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int x, k;
    cin >> x >> k;
    if(x % k == 0){
        cout << 2 << '\n';
        cout << x - 1 << ' ' << 1 << '\n';
    }else{
        cout << 1 << '\n';
        cout << x << '\n';
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
