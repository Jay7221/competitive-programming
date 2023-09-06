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
 
 
void solve() {
    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    int x2, y2, r2;
    cin >> x2 >> y2 >> r2;
    auto is_inside1= [&](int x, int y){
        ll dx = x - x1;
        ll dy = y - y1;
        dx *= dx;
        dy *= dy;
        return ((dx + dy) <= (r1 * 1ll * r1));
    };
    auto is_inside2= [&](int x, int y){
        ll dx = x - x2;
        ll dy = y - y2;
        dx *= dx;
        dy *= dy;
        return ((dx + dy) <= (r2 * 1ll * r2));
    };
    set<pair<int, int>> st;
    for(int dx = -r1; dx <= r1; ++dx){
        for(int dy = -r1; dy <= r1; ++dy){
            int x = x1 + dx;
            int y = y1 + dy;
            if(is_inside1(x, y) && is_inside2(x, y)){
                st.insert({x, y});
            }
        }
    }
    for(int dx = -r2; dx <= r2; ++dx){
        for(int dy = -r2; dy <= r2; ++dy){
            int x = x2 + dx;
            int y = y2 + dy;
            if(is_inside1(x, y) && is_inside2(x, y)){
                st.insert({x, y});
            }
        }
    }
    cout << st.size() << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
