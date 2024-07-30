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
static const int MAX = 2e5 + 7;
vector<ll> fact, inv, invFact;
ll add(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    a = ((a % MOD) + MOD) % MOD;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}
ll divide(ll a, ll b){
    return mult(a, power(b, MOD - 2));
}

 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pre(n);
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            pre[i] = 1;
        }
        else{
            pre[i] = -1;
        }
        if(i > 0){
            pre[i] += pre[i - 1];
        }
    }

    vector<int> num(n);
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            num[i] = power(2, i);
        }
        if(i > 0){
            num[i] = add(num[i], num[i - 1]);
        }
    }

    auto get = [&](int l, int r){
        int ans = num[r];
        if(l >= 0){
            ans = sub(ans, num[l]);
            ans = divide(ans, power(2, l + 1));
        }
        return ans;
    };

    map<int, int> freq;
    priority_queue<pair<int, int>> pq;
    pq.push({0, -1});

    for(int i = 0; i < n; ++i){
        while(pq.top().first > pre[i]){
            pq.pop();
        }
        if(pq.top().first == pre[i]){
            ++freq[get(pq.top().second, i)];
        }
        pq.push({pre[i], i});
    }

    ll ans = 0;
    for(auto [val, f]: freq){
        ans += (f * 1ll * (f - 1)) / 2;
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
 
