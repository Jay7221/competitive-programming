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
 
const ll MOD = 1e9 + 7;
ll addm(ll a, ll b){
    return ((a + 0ll + b) % MOD);
}
ll subm(ll a, ll b){
    return ((a + MOD - b) % MOD);
}
ll mulm(ll a, ll b){
    return ((a * 1ll * b) % MOD);
}
ll power(ll a, ll p){
    ll res = 1;
    while(p){
        if(p & 1){
            res = mulm(res, a);
        }
        a = mulm(a, a);
        p >>= 1;
    }
    return res;
}
ll inv(ll a){
    return power(a, MOD - 2);
}
ll divm(ll a, ll b){
    return mulm(a, power(b, MOD - 2));
}
const ll MAX = 2e6 + 7;
vector<ll> fact(MAX), invFact(MAX);

void pre(){
    fact[0] = invFact[0] = 1;
    for(ll i = 1; i < MAX; ++i){
        fact[i] = mulm(fact[i - 1], i);
        invFact[i] = mulm(invFact[i - 1], inv(i));
    }
}

ll com(ll n, ll m){
    if(min(n, m) < 0){
        return 0ll;
    }
    if(n < m){
        return 0ll;
    }
    return divm(fact[n], mulm(fact[m], fact[n - m]));
}
 
void solve() {
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = com(x1 + y1, x1);
    ll cur = com(x1 + y1, x1);
    ll pl = x1, pr = x1;
    for(ll s = x1 + y1 + 1; s <= x2 + y2; ++s){
        ll l = max(x1, s - y2);
        ll r = min(x2, s - y1);


        cur = mulm(cur, 2);
        if(pl < l){
            cur = subm(cur, com(s - 1, pl));
        }
        else if(l == pl){
            cur = addm(cur, com(s - 1, pl - 1));
        }
        else{
            cur = addm(cur, com(s - 1, pl - 2));
            cur = addm(cur, com(s - 1, pl - 1));
            cur = addm(cur, com(s - 1, pl - 1));
        }

        if(pr < r){
            cur = addm(cur, com(s - 1, pr + 1));
        }
        else if(pr == r){
            cur = subm(cur, com(s - 1, pr));
        }
        else{
            cur = subm(cur, com(s - 1, pr - 1));
            cur = subm(cur, com(s - 1, pr));
            cur = subm(cur, com(s - 1, pr));
        }

        ans = addm(ans, cur);
        pl = l;
        pr = r;
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    solve();
    
    return 0;
}
 
