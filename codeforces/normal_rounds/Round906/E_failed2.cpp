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
    int f(int a, int b){
        return max(a, b);
    }
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
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void set(int ind, int val){
        ind += n;
        tree[ind] = max(tree[ind], val);
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int get(int l, int r){
        l += n;
        r += n;
        int res = 0;
        while(l <= r){
            if((l & 1) == 1){
                res = f(res, tree[l]);
                ++l;
            }
            if((r & 1) == 0){
                res =  f(res, tree[r]);
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
        ranges.push_back({l, r});
    }
    vector<int> arr(n + 2), freq1(n + 2), freq2(n + 2);
    for(auto [l, r] : ranges){
        ++arr[l];
        --arr[r + 1];
    }
    auto cmp = [&](pair<int, int> p1, pair<int, int> p2){
        return p1.second < p2.second;
    };
    sort(ranges.begin(), ranges.end(), cmp);

    for(int i = 1; i <= n; ++i){
        arr[i] += arr[i - 1];
    }
    for(int i = 1; i <= n; ++i){
        freq1[i] = (arr[i] == 1) + freq1[i - 1];
        freq2[i] = (arr[i] == 2) + freq2[i - 1];
    }


    int ans = 0;
    SegmentTree stree(n + 5);
    SegmentTree stree1(n + 5);

    for(auto [l, r] : ranges){
        int val1 = freq1[r] - freq1[l - 1];
        int val2 = stree.get(l, r) - freq2[l - 1];
        int val3 = stree1.get(0, l - 1);
        ans = max(ans, val1 + max(val2, val3));
        stree.set(r, val1 + freq2[r]);
        stree1.set(r, val1);
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
 
