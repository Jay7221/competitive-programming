#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    int ans;

    ans = 0;
    int db = xb - xa;
    int dc = xc - xa;
    if(((db >= 0) && (dc >= 0)) || ((db <= 0) && (dc <= 0))){
        ans = max(ans, min(abs(db), abs(dc)));
    }

    db = yb - ya;
    dc = yc - ya;
    if(((db >= 0) && (dc >= 0)) || ((db <= 0) && (dc <= 0))){
        ans += min(abs(db), abs(dc));
    }

    ++ans;
    cout << ans << '\n';
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
