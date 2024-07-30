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
 
 
bool solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    auto is_good = [](string s){
        int sz = s.size();
        for(int i = 0; i < sz - 1; ++i){
            if(s[i] == s[i + 1]){
                return false;
            }
        }
        return true;
    };
    if(is_good(s)){
        return true;
    }
    if(!is_good(t)){
        return false;
    }
    if(t[0] != t[m - 1]){
        return false;
    }
    bool is0 = false, is1 = false;
    for(int i = 0; i < n - 1; ++i){
        if(s[i] == s[i + 1]){
            if(s[i] == '0'){
                is0 = true;
            }
            else{
                is1 = true;
            }
        }
    }
    if(is0 && is1){
        return false;
    }
    if(is0 && (t[0] == '0')){
        return false;
    }
    if(is1 && (t[0] == '1')){
        return false;
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}
 
