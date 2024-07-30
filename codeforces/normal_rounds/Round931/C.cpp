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
 
int query(int x, int y){
    cout << "? " << x << ' ' << y << endl;
    int res;
    cin >> res;
    return res;
}
void answer(int x, int y){
    cout << "! " << x << ' ' << y << endl;
    return;
}

bool check(int x, int y, int n, int m){
    if((x < 1) || (x > n) || (y < 1) || (y > m)){
        return false;
    }
    return (query(x, y) == 0);
}
 
void solve() {
    int n, m;
    cin >> n >> m;

    int r1 = query(1, 1);
    int r2 = query(n, 1);
    int r3 = query(1, m);

    int c1 = r1 + 2;
    int c2 = r2 - n + 1;
    int c3 = r3 + 1 - m;

    int x1, y1, x2, y2;

    if((c1 + c2) % 2 == 0){
        x1 = (c1 - c2) / 2;
        y1 = (c1 + c2) / 2;
    }
    else{
        x1 = -1;
        y1 = -1;
    }

    if((c1 + c3) % 2 == 0){
        x2 = (c1 + c3) / 2;
        y2 = (c1 - c3) / 2;
    }
    else{
        x2 = -1;
        y2 = -1;
    }

    if(check(x1, y1, n, m)){
        answer(x1, y1);
    }
    else{
        answer(x2, y2);
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
 
