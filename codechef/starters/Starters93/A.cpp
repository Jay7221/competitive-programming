#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int a, b;
    cin >> a >> b;
    bool flag = true;
    if((a % 2) != (b % 2)){
        flag = false;
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
