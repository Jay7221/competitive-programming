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
 
 
string solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(count(s.begin(), s.end(), '1') == 0){
        return s;
    }
    if(count(s.begin(), s.end(), '0') == 0){
        return s;
    }
    // Now s has atleast one 1
    auto check = [&](int state){
        string ch = "011";
        for(int i = 0; i < n; ++i){
            if(s[i] != ch[state]){
                return false;
            }
            state = (state + 1) % 3;
        }
        return true;
    };
    for(int i = 0; i < 3; ++i){
        if(check(i)){
            return s;
        }
    }
    for(int i = 1; i < n - 1; ++i){
        s[i] = '1';
    }
    if((n > 2) && (s[0] == '1') && (s[n - 1] == '1')){
        s[1] = '0';
    }
    return s;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        cout << solve() << '\n';
    }
    
    return 0;
}
 

