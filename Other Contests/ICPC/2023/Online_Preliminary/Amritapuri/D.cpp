#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
class DSU{
	public:
	vector<int> par, rank;
	int n;
	DSU(int n){
		this -> n = n;
		par.assign(n + 1, 0);
		rank.assign(n + 1, 1);
		for(int i = 0; i <= n; ++i){
			par[i] = i;
		}
	}
	int get(int u){
		if(u == par[u]){
			return u;
		}
		return get(par[u]);
	}
	int size(){
		return n;
	}
	void merge(int u, int v){
		u = get(u);
		v = get(v);
		if(u == v){
			return ;
		}
		--n;
		if(rank[u] < rank[v]){
			swap(u, v);
		}
		rank[u] += rank[v];
		par[v] = u;
	}
};
void solve(){
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> t1, t2;
	for(int i = 0; i < q; ++i){
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1){
			t1.push_back({l, r});
		}else{
			t2.push_back({l, r});
		}
	}
	sort(t1.begin(), t1.end());
	int cur = 0;
	DSU dsu(n);
	for(auto [l, r] : t1){
		if(cur < l){
			cur = l;
		}
		while(cur + 1 <= r){
			dsu.merge(cur, cur + 1);
			++cur;
		}
	}
	map<int, int> mp;
	cur = 1;
	for(int i = 1; i <= n; ++i){
		if(mp[dsu.get(i)] == 0){
			mp[dsu.get(i)] = cur;
			++cur;
		}
		mp[i] = mp[dsu.get(i)];
	}
	n = dsu.size();
	vector<vector<int>> graph(n + 1);
	vector<bool> vis(n + 1);
	vector<int> color(n + 1);
	bool flag = true;
	auto bfs = [&](int u){
		queue<int> q;
		vis[u] = true;
		q.push(u);
		color[u] = 1;
		while(q.size()){
			int v = q.front();
			q.pop();
			int col = color[v];
			if(col == 1){
				col = 2;
			}else{
				col = 1;
			}
			for(auto i : graph[v]){
				if(!vis[i]){
					vis[i] = true;
					color[i] = col;
					q.push(i);
				}else{
					if(color[v] == color[i]){
						flag = false;
					}
				}
			}
		}
	};
	for(auto [l, r] : t2){
		l = mp[l];
		r = mp[r];
		if(l == r){
			cout << 0 << '\n';
			return;
		}
		graph[l].push_back(r);
		graph[r].push_back(l);
	}
	int ans = 1;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			bfs(i);
			ans = mult(ans, 2);
		}
	}
	if(flag){
		cout << ans << '\n';
	}else{
		cout << 0 << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
