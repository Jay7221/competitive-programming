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
 
bool check(int n, int a, int b){
    string s = to_string(n);
    int d = s.size();
    int lhs = a * n - b;
    int rhs = 0;
    for(int i = 0; i < a * d - b; ++i){
        rhs = 10 * rhs + (s[i % d] - '0');
    }
    return (lhs == rhs);
}

const int MAX = 10000;
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    int d = to_string(n).size();

    for(int a = 1; a <= MAX; ++a){
        for(int b = max(1, a * d - 6); b <= min(MAX, a * d - 1); ++b){
            if(check(n, a, b)){
                v.push_back({a, b});
            }
        }
    }

    cout << v.size() << '\n';
    for(auto [a, b]: v){
        cout << a << ' ' << b << '\n';
    }
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
 
