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
 
const int LOGMAX = 30;
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    auto isMask = [&](int mask){
        for(int elem: a){
            if(((elem & mask) != 0) && ((elem & mask) != mask)){
                return false;
            }
        }
        return true;
    };

    vector<int> masks;

    for(int k = 0; k < LOGMAX; ++k){
        bool consumed = false;
        for(int &mask: masks){
            if(isMask(mask | (1 << k))){
                mask |= (1 << k);
                consumed = true;
                break;
            }
        }
        if(!consumed){
            masks.push_back(1 << k);
        }
    }

    vector<int> numRanges;
    for(int mask: masks){
        int ranges = 0;
        bool active = false;
        for(int elem: a){
            if((mask & elem) == 0){
                if(!active){
                    active = true;
                    ++ranges;
                }
            }
            else{
                active = false;
            }
        }
        numRanges.push_back(ranges);
    }

    int tot = a[0];
    for(int elem: a){
        tot &= elem;
    }

    int m = masks.size();

    while(q--){
        int k, x;
        cin >> k >> x;
        int res = tot;
        for(int i = 0; i < m; ++i){
            if(numRanges[i] <= k){
                res = max(res, (tot & ~x) | (masks[i] & x));
            }
        }
        cout << res << '\n';
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
 
