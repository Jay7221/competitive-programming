#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int b;
    cin >> b;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int cur = 0;
    for(int i = 0; i < 32; ++i){
        cur += (1 << i);
    }

    for(int elem : a){
        if((b & elem) == b){
            cur &= elem;
        }
    }

    bool flag = (cur == b);
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
