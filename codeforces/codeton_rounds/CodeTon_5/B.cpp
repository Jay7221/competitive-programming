#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    int cur = 0;
    for(int elem : a){
        if((elem | x) > x){
            break;
        }
        cur |= elem;
    }
    for(int elem : b){
        if((elem | x) > x){
            break;
        }
        cur |= elem;
    }
    for(int elem : c){
        if((elem | x) > x){
            break;
        }
        cur |= elem;
    }
    bool flag = (cur == x);
    if(flag){
        cout << "Yes\n";
    }else{
        cout << "No\n";
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
