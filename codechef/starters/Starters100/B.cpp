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
 

const int MAX = 1e5 + 7;
vector<bool> isPrime(MAX, true);
 
void solve() {
    int n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << -1 << '\n';
        return;
    }
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        p[i] = i + 1;
    }
    if(n % 4 == 0){
        for(int i = 0; i < n; i += 4){
            swap(p[i], p[i + 2]);
            swap(p[i + 1], p[i + 3]);
        }
    }
    if(n % 4 == 1){
        p[0] = 3;
        p[1] = 4;
        p[2] = 5;
        p[3] = 1;
        p[4] = 2;
        for(int i = 5; i < n; i += 4){
            swap(p[i], p[i + 2]);
            swap(p[i + 1], p[i + 3]);
        }
    }
    else if(n % 4 == 2){
        p[0] = 4;
        p[1] = 5;
        p[2] = 6;
        p[3] = 1;
        p[4] = 2;
        p[5] = 3;
        for(int i = 6; i < n; i += 4){
            swap(p[i], p[i + 2]);
            swap(p[i + 1], p[i + 3]);
        }
    }
    else if(n % 4 == 3){
        p[0] = 4;
        p[1] = 7;
        p[2] = 1;
        p[3] = 6;
        p[4] = 2;
        p[5] = 3;
        p[6] = 5;
        for(int i = 7; i < n; i += 4){
            swap(p[i], p[i + 2]);
            swap(p[i + 1], p[i + 3]);
        }
    }
    for(int elem : p){
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 
