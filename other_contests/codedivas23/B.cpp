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
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void set(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int get(int l, int r, int x){
        l += n;
        r += n;
        vector<int> nodes, nl, nr;
        while(l <= r){
            if((l & 1) == 1){
                nl.push_back(l);
                ++l;
            }
            if((r & 1) == 0){
                nr.push_back(r);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        for(int elem : nl){
            nodes.push_back(elem);
        }
        reverse(nr.begin(), nr.end());
        for(int elem : nr){
            nodes.push_back(elem);
        }
        for(int ind : nodes){
            if(tree[ind] <= x){
                while(ind < n){
                    int left = 2 * ind;
                    int right = left + 1;
                    if(tree[left] <= x){
                        ind = left;
                    }
                    else{
                        ind = right;
                    }
                }
                ind -= n;
                return ind;
            }
        }
        return -1;
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    SegmentTree segtree(arr);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, x;
            cin >> l >> x;
            --l;
            segtree.set(l, x);
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            int ind = segtree.get(l, r, x);
            if(ind != -1){
                ++ind;
            }
            cout << ind << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
