#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    bool flag = true;
    if((n == 3) || (n == 4) || (n == 2)){
        flag = false;
    }
    if(flag){
        cout << "Alice\n";
    }else{
        cout << "Bob\n";
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
