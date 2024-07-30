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
    vector<int> tree;
    int n;
    void init(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<int>(2 * n);
    }
    SegmentTree(){
    }
    SegmentTree(int sz){
        init(sz);
    }
    SegmentTree(vector<int> &arr){
        int sz = arr.size();
        init(sz);
        for(int i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(int i = n - 1; i > 0; --i){
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void set(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int get(int l, int r){
        l += n;
        r += n;
        int res = 0;
        while(l <= r){
            if((l & 1) == 1){
                res = max(res, tree[l]);
                ++l;
            }
            if((r & 1) == 0){
                res =  max(res, tree[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};
 
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> ranges;
    for(int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;
        ranges.push_back({r, l});
    }
    sort(ranges.begin(), ranges.end());


    vector<int> arr(n + 2), pre1(n + 2), pre2(n + 2);
    for(auto [r, l] : ranges){
        ++arr[l];
        --arr[r + 1];
    }

    for(int i = 1; i <= n; ++i){
        arr[i] += arr[i - 1];
    }

    for(int i = 1; i <= n; ++i){
        pre1[i] = (arr[i] == 1) + pre1[i - 1];
        pre2[i] = (arr[i] == 2) + pre2[i - 1];
    }


    int ans = 0;
    SegmentTree s1(n + 5), s2(n + 5);
    for(auto [r, l] : ranges){
        int no1 = pre1[r] - pre1[l - 1];
        int overlap = s1.get(l, r);
        int disjoint = s2.get(0, r);

        ans = max(ans, no1 + max(overlap, disjoint));

        s1.set(r, no1 + pre2[r]);
        s2.set(r, no1);
    }
    for(int i = 1; i <= n; ++i){
        ans += (arr[i] == 0);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
