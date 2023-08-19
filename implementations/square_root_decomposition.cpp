#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    m = sqrt(n) + 1;
    int a[n], b[m];
    memset(b, 0, sizeof(b));
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b[i / m] += a[i];
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;

        for(int i = l; i <= r; ){
            if(((i % m) == 0) && (i + m <= r + 1)){
                // b[i/m] lies completely inside range [l...r]
                ans += b[i / m];
                i += m;
            }
            else{
                ans += a[i];
                ++i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
