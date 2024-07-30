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

std::vector<int> zAlgorithm(const std::string& s, const std::string& pat) {
    std::string concat = pat + "$" + s;
    int n = concat.length();
    int m = pat.size();

    std::vector<int> zArray(n, 0);
    int left = 0, right = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= right)
            zArray[i] = std::min(right - i + 1, zArray[i - left]);

        while (i + zArray[i] < n && concat[i + zArray[i]] == concat[zArray[i]])
            ++zArray[i];

        if (i + zArray[i] - 1 > right) {
            left = i;
            right = i + zArray[i] - 1;
        }
    }
    vector<int> ans(n - m - 1);
    for(int i = 0; i < n - m - 1; ++i){
        ans[i] = zArray[i + m + 1];
    }

    return ans;
}

const int MOD = 1e9 + 7;

int mult(int a, int b){
    return (a * 1ll * b) % MOD;
}
int add(int a, int b){
    return (a + 0ll + b) % MOD;
}
int sub(int a, int b){
    return ((a - b) % MOD + MOD) % MOD;
}
int power(int a, int p){
    if(p < 0){
        return 0;
    }
    int ans = 1;
    while(p){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string srev = s;
    reverse(srev.begin(), srev.end());

    string s1 = s + srev + s;

    vector<int> z = zAlgorithm(s1, s);
    int ans = 0;
    for(int i = 0; i < 2 * n; ++i){
        ans += (z[i] == n);
    }
    ans = mult(ans, power(2, k - 1));
    int diff = 0;
    for(int i = n + 1; i < 2 * n; ++i){
        diff += (z[i] == n);
    }
    ans = sub(ans, diff);
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
 
