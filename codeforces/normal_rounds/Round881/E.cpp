#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for(int i = 0; i < m; ++i){
        cin >> l[i] >> r[i];
    }
    int q;
    cin >> q;
    vector<int> x(q);
    for(int i = 0; i < q; ++i){
        cin >> x[i];
    }
    auto check = [&](int ind){
        vector<int> pre(n + 1);
        for(int i = 0; i < ind; ++i){
            pre[x[i]] = 1;
        }
        for(int i = 1; i <= n; ++i){
            pre[i] += pre[i - 1];
        }
        for(int i = 0; i < m; ++i){
            if((2 * (pre[r[i]] - pre[l[i] - 1])) > (r[i] - l[i] + 1)){
                return true;
            }
        }
        return false;
    };
    int low = 1, hi = q;
    while(low < hi){
        int mid = (low + hi) / 2;
        if(!check(mid)){
            low = mid + 1;
        }else{
            hi = mid;
        }
    }
    if(!check(low)){
        low = -1;
    }
    cout << low << '\n';
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
