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


int dfs(int u, vector<int> &rank, vector<vector<int>> &adj){
    if(u == rank.size() - 1){
        return 1;
    }
    int ans = 0;
    for(int v: adj[u]){
        if(rank[v] < rank[u]){
            ans += dfs(v, rank, adj);
        }
    }
    return ans;
}
 int findRankedPath(vector<vector<int>> matrix, vector<int> rank) {
	int n = rank.size();
	vector<vector<int>> adj(n);
	for(vector<int> &edge: matrix){
		adj[edge[0] - 1].push_back(edge[1] - 1);
		adj[edge[1] - 1].push_back(edge[0] - 1);
	}
	vector<int> dp(n);
	dp[0] = 1;
	priority_queue<pair<int, int>> q;
	vector<bool> vis(n);
	q.push({rank[0], 0});
	
	while(!q.empty()){
		int u, r;
		tie(r, u) = q.top();
		q.pop();

		if(vis[u]){
			continue;
		}
		vis[u] = true;

		for(int v: adj[u]){
			if(rank[v] < rank[u]){
				dp[v] += dp[u];
				q.push({rank[v], v});
			}
		}
	}
	return dp[n - 1];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int p, q;
    cin >> p >> q;
    vector<vector<int>> matrix(p, vector<int>(q));
    for(int i = 0; i < p; ++i){
        for(int j = 0; j < q; ++j){
            cin >> matrix[i][j];
        }
    }
    int n;
    cin >> n;
    vector<int> rank(n);
    for(int i = 0; i < n; ++i){
        cin >> rank[i];
    }

    cout << findRankedPath(matrix, rank) << '\n';
    
    return 0;
}
 
