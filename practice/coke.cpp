#include<bits/stdc++.h>
using namespace std;
void solve(){
    int c, n1, n5, n10;
    cin >> c >> n1 >> n5 >> n10;
    int k;
    int ans = 0;

    k = min(c, n10);
    c -= k;
    n10 -= k;
    int kk = min(k, n1 / 3);
    n5 += kk;
    n1 -= 3 * kk;
    k -= kk;
    n5 += 2 * (k / 5);
    n1 += 2 * (k % 5);

    while((n5 > 0) && (n5 < 2 * c)){
        --n5;
        n1 -= 3;
        --c;
        ans += 4;
    }

    k = min(c, n5 / 2);
    ans += 2 * k;
    n5 -= 2 * k;
    c -= k;

    k = min(c, n1 / 8);
    ans += 8 * k;
    n1 -= 8 * k;
    c -= k;

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
