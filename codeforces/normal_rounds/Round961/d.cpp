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
    int n, c, k;
    cin >> n >> c >> k;

    string s;
    cin >> s;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        a[i] = s[i] - 'A';
    }
    const int MAX_MASK = (1 << c) - 1;

    vector<int> masks;
    vector<int> freq(c);
    int curMask = 0;
    for(int i = 0; i < n; ++i){
        ++freq[a[i]];
        if(freq[a[i]] == 1){
            curMask ^= (1 << a[i]);
        }
        if(i >= k){
            --freq[a[i - k]];
            if(freq[a[i - k]] == 0){
                curMask ^= (1 << a[i - k]);
            }
        }
        if(i >= k - 1){
            masks.push_back(curMask);
        }
    }

    vector<bool> dp(MAX_MASK + 1);

    for(int mask: masks){
        dp[MAX_MASK ^ mask] = true;
    }

    for(int mask = MAX_MASK; mask > 0; --mask){
        for(int ch = 0; ch < c; ++ch){
            if(1 & (mask >> ch)){
                int submask = mask ^ (1 << ch);
                dp[submask] = dp[submask] | dp[mask];
            }
        }
    }

    int res = c;
    for(int mask = 0; mask <= MAX_MASK; ++mask){
        if(!dp[mask] && (1 & (mask >> a.back()))){
            res = min(res, __builtin_popcount(mask));
        }
    }
    cout << res << '\n';
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
 
