#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
struct SegmentTree{
    const ll INF = 1e15 + 7;
    const int LOGMAX = 30;
    int n;
    vector<vector<ll>> bucketSum, bucketMin;

    SegmentTree(vector<int> &arr){
        int sz = arr.size();
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        bucketSum = vector<vector<ll>>(2 * n, vector<ll>(LOGMAX, 0ll));
        bucketMin = vector<vector<ll>>(2 * n, vector<ll>(LOGMAX, INF));
        for(int i = 0; i < sz; ++i){
            int lg = 31 - __builtin_clz(arr[i]);
            int ind = i + n;
            bucketSum[ind][lg] = arr[i];
            bucketMin[ind][lg] = arr[i];
        }
        for(int i = n - 1; i > 0; --i){
            int left = 2 * i, right = 2 * i + 1;
            for(int k = 0; k < LOGMAX; ++k){
                bucketSum[i][k] = bucketSum[left][k] + bucketSum[right][k];
                bucketMin[i][k] = min(bucketMin[left][k], bucketMin[right][k]);
            }
        }
    }

    ll query(int l, int r){
        vector<ll> bSum(LOGMAX, 0ll), bMin(LOGMAX, INF);
        l += n;
        r += n;
        while(l <= r){
            if(l & 1){
                for(int k = 0; k < LOGMAX; ++k){
                    bMin[k] = min(bucketMin[l][k], bMin[k]);
                    bSum[k] = bucketSum[l][k] + bSum[k];
                }
                ++l;
            }
            if(!(r & 1)){
                for(int k = 0; k < LOGMAX; ++k){
                    bMin[k] = min(bucketMin[r][k], bMin[k]);
                    bSum[k] = bucketSum[r][k] + bSum[k];
                }
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        ll presum = 0;
        for(int k = 0; k < LOGMAX; ++k){
            bMin[k] = min(bMin[k], (1ll << (k + 1)) - 1);
            if(presum + 1 < bMin[k]){
                break;
            }
            presum += bSum[k];
        }
        return presum + 1;
    }

};
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    SegmentTree tree(x);
    while(q--){
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << tree.query(x, y) << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    tc = 1;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
