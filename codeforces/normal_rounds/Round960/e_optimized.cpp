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
vector<int> depth;
vector<int> maxDepth;
vector<int> par;
vector<int> path;
int numOperations = 0;
int numJumps = 0;

int query(int x){
    ++x;
    cout << "? " << x << endl;
    int res;
    cin >> res;
    if(res == 0){
        ++numJumps;
    }
    ++numOperations;
    return res;
}

void answer(int x){
    ++x;
    cout << "! " << x << endl;
}


void dfs(int u, int p){
    for(int v: adj[u]){
        if(v != p){
            depth[v] = maxDepth[v] = depth[u] + 1;
            par[v] = u;
            dfs(v, u);
            maxDepth[u] = max(maxDepth[u], maxDepth[v]);
        }
    }
}

void tracePath(int u){
    path.push_back(u);
    stack<int> candidates;
    for(int v: adj[u]){
        if(v == par[u]){
            continue;
        }
        if(maxDepth[v] - depth[v] < numJumps){
            continue;
        }
        candidates.push(v);
    }

    while(!candidates.empty()){

        int v = candidates.top();
        candidates.pop();

        if(maxDepth[v] - depth[v] < numJumps){
            continue;
        }

        if(candidates.empty() || query(v)){
            tracePath(v);
            return;
        }
    }
}

bool cmp(int a, int b){
    return (maxDepth[a] - depth[a]) < (maxDepth[b] - depth[b]);
}

void solve() {
    int n;
    cin >> n;

    adj = vector<vector<int>>(n);
    depth = vector<int>(n, 1);
    maxDepth = vector<int>(n, 1);
    par = vector<int>(n);
    path.clear();
    numJumps = 0;
    numOperations = 0;


    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(0, -1);

    for(int u = 0; u < n; ++u){
        sort(adj[u].rbegin(), adj[u].rend(), cmp);
    }

    tracePath(0);

    int l = 0;
    int r = path.size() - 1;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(query(path[mid])){
            l = mid;
        }
        else{
            r = mid - 1;
            l = max(0, l - 1);
            r = max(0, r - 1);
        }
    }

    answer(path[l]);
    assert(numOperations <= 84);
}
 
int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 

