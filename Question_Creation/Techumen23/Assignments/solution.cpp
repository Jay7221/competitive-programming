#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N;
vector<vector<int>> capacity;
vector<vector<int>> adj;
int start_node, end_node;
const int INF = 1e9 + 7;

void print_capacity(){
	cerr << "    ";
	for(int i = 0; i < N; ++i){
		cerr << i << ' ' ;
	}
	cerr << "\n----------------------------\n";
	for(int i = 0; i < N; ++i){
		cerr << i << " | ";
		for(int j = 0; j < N; ++j){
			cerr << capacity[i][j] << ' ';
		}
		cerr << '\n';
	}
}
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
	int flow = 0;
	vector<int> parent(N);
	int new_flow;
	while (new_flow = bfs(s, t, parent)) {
		flow += new_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}

	return flow;
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	vector<int> k(n);
	for(int i = 0; i < n; ++i){
		cin >> k[i];
		a[i].assign(k[i], 0);
		for(int j = 0; j < k[i]; ++j){
			cin >> a[i][j];
			--a[i][j];
		}
	}
	

	N = n + m + 2;
	adj.assign(N, vector<int>());
	capacity.assign(N, vector<int>(N, 0));
	start_node = n + m;
	end_node = n + m + 1;

	auto add_edge = [&](int i, int j){
		adj[i].push_back(j);
		adj[j].push_back(i);
		capacity[i][j] = 1;
	};


	for(int i = 0; i < n; ++i){
		add_edge(start_node, i);
	}
	for(int i = 0; i < m; ++i){
		add_edge(n + i, end_node);
	}
	for(int i = 0; i < n; ++i){
		for(int assignement : a[i]){
			add_edge(i, assignement + n);
		}
	}
	cout << maxflow(start_node, end_node) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
