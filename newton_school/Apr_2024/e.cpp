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
 
ll pow(ll n, int k){
    ll res = n, ans = 1;
    while(k){
        if(k & 1){
            ans *= res;
        }
        res *= res;
        k >>= 1;
    }
    return ans;
}

ll get(ll n, int k){
    if(pow(2, k) > n){
        return 1;
    }
    int l = 2;
    int r = 10;
    while(l < r){
        int m = (l + r + 1) / 2;
        if(pow(m, k) > n){
            r = m - 1;
        }
        else{
            l = m;
        }
    }
    return pow(l, k);
}

vector<pair<int, int>> powers = {};
pair<bool, int> factors(int x){
    int f = 0;
    for(int i = 2; i <= x; ++i){
        if(x % i == 0){
            if((x % (i * i)) == 0){
                return {false, 0};
            }
            ++f;
        }
    }
    return {true, f};
}
void pre(){
    for(int i = 2; i < 60; ++i){
        bool ok;
        int f;
        tie(ok, f) = factors(i);
        if(ok){
            if(f & 1){
                powers.push_back({i, 1});
            }
            else{
                powers.push_back({i, -1});
            }
        }
    }
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for(int k = 2; k < 20; ++k){
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    cerr << powers << '\n';
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
