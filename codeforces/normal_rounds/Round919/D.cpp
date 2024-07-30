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
 
const ll MAX = 1e18 + 7;
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v, ind;
    ll cur = 0;
    for(int i = 0; i < n; ++i){
        ll b, x;
        cin >> b >> x;
        if(b == 1){
            if(cur < MAX){
                cur += 1;
                ind.push_back(cur);
                v.push_back(x);
            }
        }
        else{
            ++x;
            if(cur < MAX / x){
                cur *= x;
            }
            else{
                cur = MAX;
            }
        }
    }
    int m = ind.size();

    auto get = [&](ll k, int r){
        int l = 0;
        while(l < r){
            int m = (l + r + 1) / 2;
            if(ind[m] > k){
                r = m - 1;
            }
            else{
                l = m;
            }
        }
        return l;
    };
    for(int i = 0; i < q; ++i){
        ll k;
        cin >> k;
        int j = get(k, m - 1);
        while(k % ind[j] > 0){
            k %= ind[j];
            j = get(k, j - 1);
        }
        cout << v[j] << ' ';
    }
    cout << '\n';
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
 
