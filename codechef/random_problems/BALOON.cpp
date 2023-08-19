#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod (ll)(1e9 + 7)
void solve(){
    int n ;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = 0;
    int ans;
    for(int i = 0; i < n; i++){
        if(a[i] <= 7){
            sum += a[i];
            ans = i + 1;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
     solve();
    }
}