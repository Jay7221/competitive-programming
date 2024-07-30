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
 
vector<int> getZ(string s){
    int n = s.size();
    vector<int> z(n);
    int l = 1;
    for(int i = 1; i < n; ++i){
        z[i] = max(min(l + z[l] - i, z[i - l]), 0);
        while((i + z[i] < n) && (s[z[i]] == s[i + z[i]])){
            ++z[i];
        }
        if(l + z[l] <= i + z[i]){
            l = i;
        }
    }
    return z;
}
 
void solve() {
    string s;
    cin >> s;

    int n = s.size();
    if(n & 1){
        cout << 0 << '\n';
        return;
    }

    vector<int> pre = getZ(s);
    reverse(s.begin(), s.end());
    vector<int> suf = getZ(s);

    int ans = 0;
    for(int i = 0, j = n / 2; i <= n / 2; ++i, --j){
        ans += (pre[i] >= i) && (suf[j] >= j);
    }
    cout << ans << '\n';
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
 
