#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
struct SegTree{
    int n;
    vector<ll> tree;
    SegTree(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree.assign(2 * n, INF);
    }
    void set(int l, int r, ll val){
        l += n;
        r += n;
        while(l <= r){
            if(l & 1){
                tree[l] = min(tree[l], val);
                ++l;
            }
            if(!(r & 1)){
                tree[r] = min(tree[r], val);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
    }
    ll get(int ind){
        ind += n;
        ll ans = INF;
        while(ind > 0){
            ans = min(ans, tree[ind]);
            ind >>= 1;
        }
        return ans;
    }
};
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> l(k), r(k), a(k), b(k);
    for(int i = 0; i < k; ++i){
        cin >> l[i];
        --l[i];
    }
    for(int i = 0; i < k; ++i){
        cin >> r[i];
        --r[i];
    }
    for(int i = 0; i < k; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < k; ++i){
        cin >> b[i];
    }
    ll ans = INF;
    for(int mask = 1; mask < (1 << k); ++mask){
        ll cur = 0;
        SegTree s(n);
        for(int i = 0; i < k; ++i){
            if(1 & (mask >> i)){
                cur += a[i];
                s.set(l[i], r[i], b[i]);
            }
        }
        for(int i = 0;  i < n; ++i){
            cur += s.get(i);
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}
int main(){
    solve();
    return 0;
}
