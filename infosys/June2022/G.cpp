#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    a = ((a % MOD) + MOD) % MOD;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}
ll divide(ll a, ll b){
    return mult(a, power(b, MOD - 2));
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> l[i];
        if(l[i] > 0){
            --l[i];
        }
    }
    for(int i = 0; i < n; ++i){
        cin >> r[i];
        --r[i];
    }
    for(int i = 0; i < n; ++i){
        if(l[i] < 0){
            a[r[i]] = -l[i];
        }else{
            ll x = add(l[i] + 1, r[i] + 1);
            for(int j = l[i]; j <= r[i]; ++j){
                a[j] = mult(a[j], x);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans = add(ans, a[i]);
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















struct LazySegmentTree{
    int n;
    vector<ll> L, R, add, val;
    LazySegmentTree(int sz){
        n = 4 * sz;
        L = vector<ll>(n);
        R = vector<ll>(n);
        add = vector<ll>(n, 1);
        val = vector<ll>(n, 1);
        n >>= 1;
        init(1, 0, sz);
    }
    void init(int node, int l, int r){
        if(l > r){
            return;
        }
        L[node] = l;
        R[node] = r;
        if(l < r){
            int mid = (l + r) / 2;
            init(2 * node, l, mid);
            init(2 * node + 1, mid + 1, r);
        }
    }
    void set(int node, int l, int r, ll x){
        if((r < L[node]) || (R[node] < l)) {
            return;
        }
        if((l <= L[node]) && (R[node] <= r)){
            val[node] = mult(val[node], x);
            add[node] = mult(add[node], x);
        }else{
            set(2 * node, l, r, x);
            set(2 * node + 1, l, r, x);
            val[node] = add(val[2 * node], val[2 * node + 1]);
            val[node] = mult(val[node], add[node]);
        }
    }
    ll get(int node, int l, int r){
        if((l <= L[node]) && (R[node] <= r)){
            return val[node];
        }
        ll ans = INF;
        if(l <= R[2 * node]){
            ans = min(ans, get(2 * node, l, r));
        }
        if(L[2 * node + 1] <= r){
            ans = min(ans, get(2 * node + 1, l, r));
        }
        ans = mult(ans, add[node]);
        return ans;
    }
};

