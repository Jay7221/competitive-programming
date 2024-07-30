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
 
bool isPrime(int n){
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

const int MOD = 1e9 + 7;
ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll sub(ll a, ll b){
    return ((a - b) % MOD + MOD) % MOD;
}
ll mult(ll a, ll b){
    return (a * b) % MOD;
}

ll power(ll a, ll p){
    ll ans = 1;
    while(p){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}

int lcd(int x){
    for(int i = 2; i <= 60; ++i){
        if(x % i == 0){
            return i;
        }
    }
    return 1;
}
int lcd(int x, int y){
    for(int i = 2; i <= 60; ++i){
        if((x % i == 0) && (y % i == 0)){
            return i;
        }
    }
    return 1;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0; i < n; ++i){
        int elem;
        cin >> elem;
        if(elem % k == 0){
            a.push_back(elem);
        }
    }

    if(!isPrime(k)){
        cout << 0 << '\n';
        return;
    }

    auto get = [](int n){
        return sub(power(2, n), 1);
    };
    int ans = get(a.size());

    vector<int> primes;
    for(int i = 2; i < k; ++i){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }

    int m = primes.size();
    vector<int> dp(1 << m);

    for(int elem: a){
        int mask = 0;
        for(int i = 0; i < m; ++i){
            if(elem % primes[i] == 0){
                mask |= (1 << i);
            }
        }
        for(int cur = mask; cur > 0; cur = (cur - 1) & mask){
            ++dp[cur];
        }
    }

    for(int mask = 0; mask < (1 << m); ++mask){
        if(__builtin_popcount(mask) & 1){
            ans = sub(ans, get(dp[mask]));
        }
        else{
            ans = add(ans, get(dp[mask]));
        }
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
 
