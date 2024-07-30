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
 

#define ll long long

vector<int> par;
vector<vector<int>> adj;

void dfs(int u, int p){
    par[u] = p;
    for(int v: adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}

int getMaxSubset(int N, int M, int Two, vector<vector<int>> edges, vector<int> C){

    par = vector<int>(N);
    adj = vector<vector<int>>(N);

    for(int i = 0; i < M; ++i){
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1; adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    vector<ll> dp(N);
    queue<ll> q;
    priority_queue<ll> pq;

    q.push(0);
    pq.push(0);

    ll prev = 0;

    while(!q.empty()){
        queue<ll> nq;
        priority_queue<ll> npq;
        npq.push(0);

        while(!q.empty()){
            ll u = q.front();
            ll p = par[u];

            q.pop();

            dp[u] = prev;

            if(p != -1){
                if(dp[p] == pq.top()){
                    pq.pop();
                    dp[u] = max(dp[u], pq.top());
                    pq.push(dp[p]);
                }
                else{
                    dp[u] = max(dp[u], pq.top());
                }
            }

            dp[u] += C[u];
            if(dp[u] < 0){
                cerr << u << '\n';
            }

            npq.push(dp[u]);
            for(ll v: adj[u]){
                if(v != par[u]){
                    nq.push(v);
                }
            }
        }

        prev = pq.top();
        q = nq;
        pq = npq;
    }


    const ll MOD = 1e9 + 7;
    return (*max_element(dp.begin(), dp.end())) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int two;
    cin >> two;
    vector<vector<int>> edges;
    vector<int> c(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        edges.push_back((vector<int>){u, v});
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    cout << getMaxSubset(n, m, two, edges, c) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
