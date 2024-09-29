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
 
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

struct SegmentTree{
    int f(int a, int b){
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
    vector<int> arr(MAX_N), ind(MAX_N, n), nextInd(MAX_N, n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int q;
    cin >> q;
    int two;
    cin >> two;
    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end());

    for(int i = n - 1; i >= 0; --i){
        nextInd[i] = ind[arr[i]];
        ind[arr[i]] = i;
    }
    vector<int> contribution(n + 1);
    for(int i = 0; i < n; ++i){
        if(ind[arr[i]] == i){
            contribution[i] = 1;
            if(ind[arr[i] + 1] < ind[arr[i]]){
                --contribution[i];
            }
            if(ind[arr[i] - 1] < ind[arr[i]]){
                --contribution[i];
            }
        }
    }

    SegmentTree tree(contribution);

    int curInd = 0;
    vector<int> res(q);
    for(auto [l, r, i]: queries){
        while(curInd < l){
            int elem = arr[curInd];
            if(ind[elem + 1] > ind[elem]){
                ++contribution[ind[elem + 1]];
                tree.set(ind[elem + 1], contribution[ind[elem + 1]]);
            }
            if(ind[elem - 1] > ind[elem]){
                ++contribution[ind[elem - 1]];
                tree.set(ind[elem - 1], contribution[ind[elem - 1]]);
            }
            ind[elem] = nextInd[elem];
            ++contribution[ind[elem]];
            if(ind[elem + 1] < ind[elem]){
                --contribution[ind[elem]];
            }
            if(ind[elem - 1] < ind[elem]){
                --contribution[ind[elem]];
            }
            ++curInd;
        }
        res[i] = tree.get(l, r);
    }

    cout << (accumulate(res.begin(), res.end(), 0ll) % MOD) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
