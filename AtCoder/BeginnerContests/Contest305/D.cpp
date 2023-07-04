#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pre(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 2; i < n; i += 2){
        pre[i] = a[i] - a[i - 1];
    }
    for(int i = 1; i < n; ++i){
        pre[i] += pre[i - 1];
    }
    auto get = [&](int t){
        if(t < 0){
            return 0;
        }
        int i = lower_bound(a.begin(), a.end(), t) - a.begin();
        int ans = pre[i];
        if(i % 2 == 0){
            ans -= a[i] - t;
        }
        return ans;
    };
    int q;
    cin >> q;
    for(int query = 0; query < q; ++query){
        int l, r;
        cin >> l >> r;
        int ans = get(r) - get(l);
        cout << ans << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    return 0;
}
