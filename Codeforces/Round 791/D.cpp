#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){ cerr << c << ' ' ;} cerr << '\n';
void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > g(n);
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
	}
	ll l = 0, r = *max_element(a.begin(), a.end()) + 1;
	while(l < r){
		ll mid = (l + r) / 2;
		vector<int> f(n), in(n);
		queue<int> next;
		// next -> nodes to be processed next
		// f[x] = length of the longest path ending at node x
		// in[x] = number of paths coming into node x
		int valid_nodes = 0;
		// valid_nodes -> number of nodes such that a[i] <= mid and can be included in the path
		// without making max greater than mid
		for(int i = 0; i < n; ++i){
			if(a[i] <= mid){
				++valid_nodes;
				for(auto c : g[i])
					++in[c];
				f[i] = 1;
			}
		}
		for(int i = 0; i < n; ++i){
			if(a[i] <= mid && in[i] == 0)
				next.push(i);
		}
		while(next.size()){
			int u = next.front();
			--valid_nodes;	// we have used up one valid node as starting point
			 next.pop();
			for(auto c : g[u]){
				if(a[c] <= mid)
					f[c] = max(f[c], f[u] + 1);
				--in[c];
				if(a[c] <= mid && in[c] == 0)
					next.push(c);
			}
		}
		// if valid_nodes > 0  implies that there is a cycle in graph
		// max_element(f) >= k or if there are cycles in the graph 
		// implies that it is possible to construct a path such that
		// the maximum element is at most mid and thus mid >= ans
		if(valid_nodes || *max_element(f.begin(), f.end()) >= k){
			r = mid;
		}
		else
			l = mid + 1;
	}
	if(l == *max_element(a.begin(), a.end()) + 1)
		cout << -1 << '\n';
	else 
		cout << l << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}