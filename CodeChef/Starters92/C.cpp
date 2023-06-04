#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int w, l;
    cin >> w >> l;
    bool flag = false;
    if(((w & 1) == 0) || ((l & 1) == 0)){
        flag = true;
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
