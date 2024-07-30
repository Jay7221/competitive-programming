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
 
void put(ll p1, ll p2){
    cout << p1 << ' ' << p2 << endl;
}
void get(ll &p1, ll &p2){
    cin >> p1 >> p2;
}
 
void solve() {
    ll n;
    cin >> n;
    bool turn = true;
    if(__builtin_popcountll(n) & 1){
        turn = false;
    }
    if(turn){
        cout << "first" << endl;
    }
    else{
        cout << "second" << endl;
    }
    while (true) {
        if(turn){
            ll p1 = 1;
            while((p1 << 1) < n){
                p1 <<= 1;
            }
            put(p1, n ^ p1);
        }
        else{
            ll p1, p2;
            get(p1, p2);
            if((p1 == 0) && (p2 == 0)){
                return;
            }
            if(__builtin_popcountll(p1) & 1){
                n = p2;
            }
            else{
                n = p1;
            }
        }
        turn ^= 1;
    }
}
 
int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
