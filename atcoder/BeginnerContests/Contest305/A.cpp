#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i <= 100; i += 5){
        if(abs(n - ans) > abs(n - i)){
            ans = i;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    return 0;
}
