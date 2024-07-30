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
    void set(ll ind, ll val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    ll get(ll l, ll r){
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
 
const ll MAX = 3e5 + 7;
const ll MOD = 998244353;
vector<ll> fact(MAX);
void pre(){
    fact[0] = 1;
    for(ll i = 1; i < MAX; ++i){
        fact[i] = fact[i - 1];
        fact[i] *= i;
        fact[i] %= MOD;
    }
}
ll power(ll a, ll p){
    ll ans = 1;
    while(p){
        if(p & 1){
            ans = (ans * a) % MOD;
        }
        p >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}
ll inv(ll a){
    return power(a, MOD - 2);
}
void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<ll> gt, lt;
    SegmentTree tree(n);
    for(ll i = 0; i < n - 1; ++i){
        if(s[i] == '>'){
            gt.insert(i + 1);
        }
        if(s[i] == '<'){
            lt.insert(i + 1);
        }
        if(s[i] == '?'){
            tree.set(i + 1, 1);
        }
    }
    auto com = [&](int a, int b){
        if(b > a){
            return 0ll;
        }
        return (fact[a] * inv((fact[a - b] * fact[b]) % MOD)) % MOD;
    };
    auto calc = [&](){
        if(s[0] == '?'){
            return 0ll;
        }
        ll tot = tree.get(0, n - 1);
        if(lt.empty() || gt.empty()){
            return fact[tot];
        }
        ll l1 = *lt.begin(), l2 = *gt.begin();
        ll del = tree.get(0, max(l1, l2));
        ++tot;
        ++del;
        ll ans = com(tot, del);
        tot -= del;
        --del;
        ans *= (fact[del] * fact[tot]) % MOD;
        ans %= MOD;
        return ans;
    };
    cout << calc() << '\n';
    while(m--){
        ll ind;
        char ch;
        cin >> ind >> ch;
        --ind;
        if(s[ind] == '>'){
            gt.erase(ind + 1);
        }
        if(s[ind] == '<'){
            lt.erase(ind + 1);
        }
        if(s[ind] == '?'){
            tree.set(ind + 1, 0);
        }
        s[ind] = ch;
        if(s[ind] == '>'){
            gt.insert(ind + 1);
        }
        if(s[ind] == '<'){
            lt.insert(ind + 1);
        }
        if(s[ind] == '?'){
            tree.set(ind + 1, 1);
        }
        cout << calc() << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    solve();
    
    return 0;
}
 
