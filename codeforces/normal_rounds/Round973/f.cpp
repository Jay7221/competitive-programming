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
 

vector<vector<int>> adj;

int bob;
vector<int> dista, distb;

int dfs0(int u, int p){
    for(int v: adj[u]){
        if(v != p){
            dista[v] = dista[u] + 1;
            dfs0(v, u);
        }
    }
    return -1;
}

int dfs1(int u, int p){
    for(int v: adj[u]){
        if(v != p){
            distb[v] = distb[u] + 1;
            dfs1(v, u);
        }
    }
    return -1;
}


int dfsAlice(int u, int p){
    if(dista[u] > distb[u]){
        return 0;
    }
    int d = 0;
    for(int v: adj[u]){
        if(v != p){
            d = max(d, dfsAlice(v, u));
        }
    }
    return d + 1;
}

int dfsBob(int u, int p){
    if(dista[u] <= distb[u]){
        return 0;
    }
    int d = 0;
    for(int v: adj[u]){
        if(v != p){
            d = max(d, dfsBob(v, u));
        }
    }
    return d + 1;
}
 
bool solve() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> bob >> bob;
    --bob;

    dista = vector<int>(n, n + 1);
    distb = vector<int>(n, n + 1);

    dista[0] = 0;
    distb[bob] = 0;

    dfs0(0, -1);
    dfs1(bob, -1);
    return (dfsAlice(0, -1) > dfsBob(bob, -1));
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }
    
    return 0;
}
 
