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
    string s;
    cin >> s;
    int n = s.size();
    s = "$" + s;
    auto generate = [&](int ind, int k){
        vector<string> v;
        string cur;
        cur.push_back(s[ind]);
        for(int i = ind * k; i <= n; i *= k){
            cur.push_back(s[i]);
            v.push_back(cur);
            cerr << i << ' ' << k << " : " << cur << '\n';
        }
        return v;
    };
    map<string, int> mp;
    for(int i = 1; i <= n; ++i){
        string tmp;
        tmp.push_back(s[i]);
        ++mp[tmp];
        for(int k = 2; k <= n; ++k){
            for(string ss : generate(i, k)){
                ++mp[ss];
            }
        }
    }
    int mx = 0;
    string ans;
    for(auto [s, f] : mp){
        if(f > mx){
            mx = f;
            ans = s;
        }
    }
    cout << mx << '\n';
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
