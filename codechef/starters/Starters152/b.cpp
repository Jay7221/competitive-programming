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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        --a[i];
    }

    vector<vector<int>> freq(n + 1, vector<int>(3));
    for(int i = 1; i <= n; ++i){
        for(int digit = 0; digit < 3; ++digit){
            freq[i][digit] = freq[i - 1][digit] + (a[i] == digit);
        }
    }

    auto getFreq = [&](int l, int r, int digit){
        return (freq[r][digit] - freq[l - 1][digit]);
    };

    auto check = [&](int l, int r){
        int len = r - l + 1;
        if(len & 1){
            return false;
        }
        for(int digit = 0; digit < 3; ++digit){
            if(getFreq(l, r, digit) == len / 2){
                return true;
            }
        }
        return false;
    };

    while(q--){
        int l, r;
        cin >> l >> r;
        if(check(l, r)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
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
 
