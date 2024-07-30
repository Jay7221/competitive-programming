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
 
vector<vector<pair<ll, ll>>> adj;
vector<ll> pre;
vector<ll> subtree;
vector<map<ll, ll>*> preSet;
vector<map<ll, ll>*> heads;
ll res = 0;

void dfs(ll u, ll p){
    for(auto pr: adj[u]){
        ll v, w;
        tie(v, w) = pr;
        if(v != p){
            pre[v] = pre[u] + w;
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    }
}

void mergeSets(ll u, ll v){
    map<ll, ll>* mp1 = preSet[u];
    map<ll, ll>* mp2 = preSet[v];
    map<ll, ll>* h1 = heads[u];
    map<ll, ll>* h2 = heads[v];
    if(mp1 -> size() < mp2 -> size()){
        swap(mp1, mp2);
        swap(h1, h2);
    }
    for(auto pr: *mp2){
        ll val, freq;
        tie(val, freq) = pr;
        res += (*mp1)[2 * pre[u] - val] * freq - (*h1)[2 * pre[u] - val] * (*h2)[val];

        (*mp1)[val] += freq;
        if(val != pre[u]){
            (*h1)[val] += (*h2)[val];
        }
        else{
            (*h1)[val] = 1;
        }
    }

    preSet[u] = mp1;
    heads[u] = h1;
}

void merge(ll u, ll p){
    for(auto pr: adj[u]){
        ll v, w;
        tie(v, w) = pr;
        if(v != p){
            merge(v, u);
            mergeSets(u, v);
        }
    }
}
 
void solve() {
    ll n;
    cin >> n;
    adj = vector<vector<pair<ll, ll>>>(n);
    for(ll i = 0; i < n - 1; ++i){
        ll u, v, w;
        cin >> u >> v >> w;

        --u, --v;
        w = 1 - 2 * w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    pre = vector<ll>(n);
    subtree = vector<ll>(n, 1);
    preSet = vector<map<ll, ll>*>(n, NULL);
    heads = vector<map<ll, ll>*>(n, NULL);

    dfs(0, -1);

    for(ll i = 0; i < n; ++i){
        preSet[i] = new map<ll, ll>();
        heads[i] = new map<ll, ll>();
        (*preSet[i])[pre[i]] = 1;
        (*heads[i])[pre[i]] = 1;
    }

    res = 0;
    merge(0, -1);

    cout << res << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
