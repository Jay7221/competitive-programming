#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
#define inf (int)(1e9 + 7)
void print(tuple<int, int, int> t){
	int a, b, c;
	tie(a, b, c) = t;
	cerr << "(" << a << ", " << b << ", " << c << ")";
}
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > graph(n);
	vector<vector<int> > dist(n, vector<int>(n, inf)); 
	vector<int> S(n);
	for(int i = 0; i < n; ++i){
		cin >> S[i];
	}
	for(int i = 0; i < k; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		--u, --v;
		graph[u].push_back(v);
		dist[u][v] = d;
	}
	vector<vector<bool> > vis(n, vector<bool>(m + 1));
	vector<vector<int> > Min(n, vector<int>(m + 1, inf));
	auto cmp = [&](tuple<int, int, int> x, tuple<int, int, int> y){
		int a, b, c, d, e, f;
		tie(a, b, c) = x;
		tie(d, e, f) = y;
		return a < d;
	};
	set<tuple<int, int, int> > unVisited;
	Min[0][m] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m + 1; ++j){
			unVisited.insert({Min[i][j], i, j});
		}
	}
	while(unVisited.size()){
		int dd, u, mm;
		tie(dd, u, mm) = *unVisited.begin();
		unVisited.erase(unVisited.begin());
		if(dd == inf)
			break ;
		for(auto v : graph[u]){
			if(mm < S[v])
				continue ;
			if(Min[v][mm - S[v]] > dd + dist[u][v]){
				unVisited.erase({Min[v][mm - S[v]], v, mm - S[v]});
				Min[v][mm - S[v]] = dd + dist[u][v];
				unVisited.insert({Min[v][mm - S[v]], v, mm - S[v]});
			}
		}
	}
	cout << *min_element(Min[n - 1].begin(), Min[n - 1].end()) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}