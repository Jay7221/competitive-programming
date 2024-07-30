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
 
#define pb push_back

struct SegmentTree{
    ll f(ll a, ll b){
        return (a + b);
    }
    vector<ll> tree;
    ll n;
    void init(ll sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<ll>(2 * n);
    }
    SegmentTree(){
    }
    SegmentTree(ll sz){
        init(sz);
    }
    SegmentTree(vector<ll> &arr){
        ll sz = arr.size();
        init(sz);
        for(ll i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(ll i = n - 1; i > 0; --i){
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void sg_update(ll ind, ll val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    ll sg_query(ll l, ll r){
        l += n;
        r += n;
        ll res = 0;
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


 
void solve(){
    ll n,q; 
    cin >> n;
    string s; cin >> s;
    cin >> q;
    while(q--){
        ll type, l, r; cin >> type >>  l >> r;
        l--, r--;
        if(type == 1){
            for(int i = l; i <= r; ++i){
                if(s[i] == 'a'){
                    s[i] = 'b';
                }
                else{
                    s[i] = 'a';
                }
            }
        }
        else{
            int cnt = 0;
            for(int i = l; i < r; ++i){
                cnt += (s[i] != s[i + 1]);
            }
            if(type == 2){
                if(cnt == r - l){
                    cout << "Yes\n";
                }
                else{
                    cout << "No\n";
                }
            }
            else{
                if(cnt == 0){
                    cout << "Yes\n";
                }
                else{
                    cout << "No\n";
                }
            }
        }
    }

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
