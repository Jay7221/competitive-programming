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
 
 
vector<int> zFunction(const string &s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    auto cmp = [&](int i, int j){
        return ((s[i] == s[j]) || (s[i] == '?') || (s[j] == '?'));
    };
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && cmp(z[i], z[i] + i)) {
            ++z[i];
        }
    }
    return z;
}

int get_max_tandem(string s){
    vector<int> v = zFunction(s);
    int n = s.size();
    for(int i = n - 1; i > 0; --i){
        if(v[i] == i){
            return 2 * i;
        }
    }
    return 0;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, get_max_tandem(s.substr(i, n - i)));
    }
    reverse(s.begin(), s.end());
    for(int i = 0; i < n; ++i){
        ans = max(ans, get_max_tandem(s.substr(i, n - i)));
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
 