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
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
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
 
void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll mx = *max_element(a.begin(), a.end());

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i < n; ++i){
        pq.push(a[i]);
    }

    while((k > 0) && (2 * pq.top() <= mx)){
        pq.push(2 * pq.top());
        pq.pop();
        --k;
    }

    while((k % n) > 0){
        pq.push(2 * pq.top());
        pq.pop();
        --k;
    }

    ll res = 0;
    while(!pq.empty()){
        ll elem = pq.top();
        pq.pop();

        res = add(res, mult(elem, power(2, k / n)));
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
 
