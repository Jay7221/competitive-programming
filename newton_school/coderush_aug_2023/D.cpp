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
 
int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        v.push_back({a[i], 1});
    }

    vector<int> ans(n);
    for(int i = 0; i < n; ++i){
        vector<pair<int, int>> tmp;
        int prev = -1;
        for(auto [x, f] : v){
            ans[i] = max(ans[i], x);

            if(prev != -1){
                tmp.push_back({gcd(prev, x), 1});
            }
            if(f > 1){
                tmp.push_back({x, f - 1});
            }
            prev = x;

        }
        v.clear();
        for(auto [x, f] : tmp){
            if(!v.empty() && (v.back().first == x)){
                v.back().second += f;
            }
            else{
                v.push_back({x, f});
            }
        }
    }

    for(int elem : ans){
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
