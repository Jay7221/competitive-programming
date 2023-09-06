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
 
 
const int MAX = 5e6 + 7;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for(int i = 1; i < n; ++i){
        int p;
        cin >> p;
        --p;
        tree[p].push_back(i);
    }
    auto subset_sum = [](vector<int> &weights, bitset<MAX> &p){
        p[0] = true;
        map<int, int> freq;
        for(int w : weights){
            ++freq[w];
        }
        vector<int> v;
        for(auto [elem, f] : freq){
            for(int i = 1; i <= f; i <<= 1){
                v.push_back(i * elem);
                f -= i;
            }
            if(f > 0){
                v.push_back(f * elem);
            }
        }
        for(int w : v){
            p |= (p << w);
        }
    };
    auto get = [&](vector<int> &a){
        if(a.empty()){
            return 0;
        }
        sort(a.rbegin(), a.rend());
        ll cs = 0;
        for(int x : a){
            cs += x;
        }
        if(a[0] * 2 >= cs){
            return a[0];
        }

        int n = a.size();
        a.push_back(0);
        int pi = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] != a[i - 1]){
                ll cnt = i - pi;
                ll x = a[i - 1];

                ll j = 1; 
                while(j < cnt){
                }
                b.push_back(x * cnt);
            }
        }
    };
    vector<int> subtree_size(n, 1);
    function<void(int)> dfs;
    ll ans = 0;
    dfs = [&](int u){

        vector<int> a;

        for(int v : tree[u]){
            dfs(v);
            subtree_size[u] += subtree_size[v];
            a.push_back(subtree_size[v]);
        }

        ll cur = 0;
        ll x = get(a);
        ans += x * (subtree_size[u] - 1 - x);
    };
    dfs(0);
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
