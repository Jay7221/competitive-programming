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
 
ll MOD = 1e9 + 7;
vector<ll> fact, inv, invFact;
inline ll add(ll a, ll b){
    return ((a + b) % MOD);
}
inline ll sub(ll a, ll b){
    return (((a - b) % MOD + MOD) % MOD);
}
inline ll mult(ll a, ll b){
    return ((a * b) % MOD);
}

const int maxB = 2e3 + 7;
int com[maxB][maxB];
int powOf[maxB][maxB];

void pre(){
    com[0][0] = 1;
    for(int i = 1; i < maxB; ++i){
        com[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            com[i][j] = add(com[i - 1][j], com[i - 1][j - 1]);
        }
    }

    for(int i = 1; i < maxB; ++i){
        powOf[i][0] = 1;
        for(int j = 1; j < maxB; ++j){
            powOf[i][j] = mult(powOf[i][j - 1], i);
        }
    }
}


int getNumberWays(int p, int b, int k, int d){
    // Number of ways to fill p places from b digits, such that there are exactly k distinct digits and d of them have already been used previously
    if(k < d){
        return 0;
    }
    int ans = 0;
    int sign = 1;
    for(int x = 0; x <= k - d; ++x){
        ans = add(ans,
                mult(sign,
                    mult(com[k - d][x],
                        powOf[k - x][p]
                    )));
        sign = -sign;
    }
    ans = mult(ans, com[b - d][k - d]);
    return ans;
}
int count0(vector<int> a, int b, int k){
    int n = a.size();
    int ans = 0;
    vector<bool> vis(b);
    int p = n;
    int d = 0;

    for(int elem: a){
        --p;

        int cnt = accumulate(vis.begin(), vis.begin() + elem, 0);

        ans = add(ans, mult(cnt, getNumberWays(p, b, k, d)));
        ans = add(ans, mult(elem - cnt, getNumberWays(p, b, k, d + 1)));


        if(!vis[elem]){
            vis[elem] = true;
            ++d;
        }
    }
    return ans;
}

int count(vector<int> a, int b, int k){
    int n = a.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);

    vector<bool> vis(b);
    int digit_count = 0;

    for(int i = 0; i < n; ++i){
        for(int d = 0; d < a[i]; ++d){
            if(vis[d]){
                dp[i + 1][digit_count] = add(1, dp[i + 1][digit_count]);
            }
            else{
                dp[i + 1][digit_count + 1] = add(1, dp[i + 1][digit_count + 1]);
            }
        }
        for(int dc = 0; dc <= min(n, b); ++dc){
            dp[i + 1][dc] = add(dp[i + 1][dc], mult(dp[i][dc], dc));
            dp[i + 1][dc + 1] = add(dp[i + 1][dc + 1], mult(dp[i][dc], b - dc));
        }
        if(!vis[a[i]]){
            vis[a[i]] = true;
            ++digit_count;
        }
    }
    return dp[n][k];
}

bool check(vector<int> a, int b, int k){
    vector<bool> vis(b);
    for(int digit: a){
        vis[digit] = true;
    }
    return (accumulate(vis.begin(), vis.end(), 0) == k);
}
 
int solve() {
    int n, B, k;
    cin >> n >> B >> k;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> r[i];
    }
    return add(check(r, B, k), sub(count(r, B, k), count(l, B, k)));
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << solve() << '\n';
    }
    
    return 0;
}
 
