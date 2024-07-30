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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> back(n, vector<int>(n, -1));
    // back[i][j] = k => [i:k], [k + 1:j]
    // back[i][j] = -1 => calculate mex

    for(int i = 0; i < n; ++i){
        dp[i][i] = max(a[i], 1);
    }

    for(int len = 2; len <= n; ++len){
        for(int i = 0, j = len - 1; j < n; ++i, ++j){
            dp[i][j] = len * len;
            for(int k = i; k < j; ++k){
                if(dp[i][j] < dp[i][k] + dp[k + 1][j]){
                    dp[i][j] = dp[i][k] + dp[k + 1][j];
                    back[i][j] = k;
                }
            }
        }
    }

    vector<pair<int, int>> operations;

    auto operate = [&](int l, int r){
        operations.push_back({l, r});
    };
    function<void(int, int)> make_perm = [&](int l, int r){
        // assuming a[l:r] are all zeros
        if(l == r){
            return;
        }
        make_perm(l, r - 1);
        operate(l, r);
        operate(l, r - 1);
        make_perm(l, r - 1);
    };
    function<void(int, int)> calc = [&](int l, int r){
        if(l == r){
            if(a[l] == 0){
                operate(l, l);
            }
            return;
        }
        if(back[l][r] == -1){
            bool zero = false;
            for(int i = l; i <= r; ++i){
                if(a[i] == 0){
                    zero = true;
                }
            }
            if(zero){
                operate(l, r);
                operate(l, r);
            }
            else{
                operate(l, r);
            }
            make_perm(l, r);
            operate(l, r);
        }
        else{
            calc(l, back[l][r]);
            calc(back[l][r] + 1, r);
        }
    };



    calc(0, n - 1);
    cout << dp[0][n - 1] << ' ' << operations.size() << '\n';
    for(auto [l, r]: operations){
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
