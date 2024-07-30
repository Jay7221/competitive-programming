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
 
ll n;
vector<vector<ll>> child;
vector<ll> a;

pair<ll, vector<ll>> dfs(ll u){
    ll ans = 0;
    vector<ll> rem(n);
    if(child[u].empty()){
        rem[0] = -1;
    }
    else{
        ll req = a[u];
        for(ll v: child[u]){
            req -= a[v];
            vector<ll> vrem;
            ll vans;
            tie(vans, vrem) = dfs(v);

            ans += vans;
            for(ll i = 1; i < n; ++i){
                if(vrem[i] == -1){
                    rem[i] = -1;
                }
                else if(rem[i] != -1){
                    rem[i] += vrem[i];
                }
            }
        }
        if(req > 0){
            for(ll i = 1; i < n; ++i){
                if(rem[i] == -1){
                    ans += i * req;
                    break;
                }
                else{
                    if(req > rem[i]){
                        ans += i * rem[i];
                        req -= rem[i];
                        rem[i] = 0;
                    }
                    else{
                        ans += i * req;
                        rem[i] -= req;
                        req = 0;
                        break;
                    }
                }
            }
        }
        else{
            rem[0] = -req;
        }
    }
    for(ll i = n - 1; i > 0; --i){
        rem[i] = rem[i - 1];
    }
    return {ans, rem};
}
 
void solve() {
    cin >> n;

    a = vector<ll>(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<ll> par(n, -1);
    for(ll i = 1; i < n; ++i){
        cin >> par[i];
        --par[i];
    }

    child = vector<vector<ll>>(n);
    for(ll i = 1; i < n; ++i){
        child[par[i]].push_back(i);
    }

    ll ans;
    vector<ll> v;
    tie(ans, v) = dfs(0);
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
 
