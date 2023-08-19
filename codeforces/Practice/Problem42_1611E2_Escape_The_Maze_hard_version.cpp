#include<bits/stdc++.h>
using namespace std;
static const int INF = 1e9 + 7;
int n;
int k;
vector<int> minDist;
vector<vector<int>> graph;
vector<int> x;
int ans, curDist;

void print(vector<int> &v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void printNodes(vector<int> &v){
	for(int elem : v){
		cerr << elem + 1 << ' ';
	}
	cerr << '\n';
}

bool dfs(int u, int p){
	if((graph[u].size() == 1) && (u != 0)){
		if(curDist < minDist[u]){
			ans = -1;
			return false;
		}
		++ans;
		return true;
	}else{
		if(minDist[u] <= curDist){
			++ans;
			return true;
		}
		for(int v : graph[u]){
			if(v != p){
				++curDist;
				if(!dfs(v, u)){
					return false;
				}
				--curDist;
			}
		}
		return true;
	}
}
int dfs2(int u, int p, int dist){
	if((u != 0) && (graph[u].size() == 1)){
		if(dist < minDist[u]){
			return -1;
		}
		return 1;
	}else{
		if(dist >= minDist[u]){
			return 1;
		}
		int ans = 0;
		for(int v : graph[u]){
			if(v != p){
				int tmp = dfs2(v, u, dist + 1);
				if(tmp == -1){
					return -1;
				}
				ans += tmp;
			}
		}
		return ans;
	}
}
void solve(){
	cin >> n >> k;
	graph.assign(n, vector<int>());
	minDist.assign(n, INF);
	x.assign(k, 0);
	for(int i = 0; i < k; ++i){
		cin >> x[i];
		--x[i];
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	queue<int> q;
	for(int u : x){
		minDist[u] = 0;
		q.push(u);
	}
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int v : graph[u]){
			if(minDist[v] > minDist[u] + 1){
				minDist[v] = minDist[u] + 1;
				q.push(v);
			}
		}
	}
	// ans = 0;
	// curDist = 0;
	// dfs(0, -1);
	// cout << ans << '\n';
	cout << dfs2(0, -1, 0) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}