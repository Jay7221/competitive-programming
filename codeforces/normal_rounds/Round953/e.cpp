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
    inline int f(int a, int b){
        return (a + b);
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
        tree[ind] = val;
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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int q;
    cin >> q;
    vector<pair<int, int>> queries;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries.push_back({l, r});
    }

    auto indb = [&](int i){
        if((i < 0) || (i > n - 1)){
            return 0;
        }
        if(b[i] == '1'){
            return 1;
        }
        if((i > 0) && (i < n - 1) && (a[i - 1] == a[i + 1]) && (a[i + 1] == '0')){
            return 1;
        }
        return 0;
    };
    auto inda = [&](int i){
        return ((a[i] == '1') || (indb(i - 1) && indb(i + 1)));
    };

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        arr[i] = inda(i);
    }
    SegmentTree tree(arr);

    for(auto [l, r]: queries){
        int ans = (a[l] == '1');
        if(r != l){
            ans += (a[r] == '1');
        }
        if(l + 1 < r){
            if(a[l + 1] == '1'){
                ++ans;
            }
            else if(b[l] == '1'){
                if(l + 2 == r){
                    ans += (b[l + 2] == '1');
                }
                else{
                    ans += indb(l + 2);
                }
            }
        }
        if(l + 1 < r - 1){
            if(a[r - 1] == '1'){
                ++ans;
            }
            else{
                ans += (b[r] == '1') && indb(r - 2);
            }
        }

        ans += tree.get(l + 2, r - 2);

        cout << ans << '\n';
    }
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
 
