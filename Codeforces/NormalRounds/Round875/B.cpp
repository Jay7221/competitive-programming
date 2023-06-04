#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    vector<int> maxa(2 * n + 1), maxb(2 * n + 1);
    int cnt = 0;
    int prev = -1;
    for(int i = 0; i < n; ++i){
        if(prev != a[i]){
            cnt = 0;
        }
        ++cnt;
        maxa[a[i]] = max(maxa[a[i]], cnt);
        prev = a[i];
    }
    prev = -1;
    for(int i = 0; i < n; ++i){
        if(prev != b[i]){
            cnt = 0;
        }
        ++cnt;
        maxb[b[i]] = max(maxb[b[i]], cnt);
        prev = b[i];
    }
    int ans = 0;
    for(int i = 0; i <= 2 * n; ++i){
        ans = max(ans, maxa[i] + maxb[i]);
    }
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
