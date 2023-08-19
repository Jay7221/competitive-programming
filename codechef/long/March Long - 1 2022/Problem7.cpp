#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
#define inf (int)(1e5)
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ';} cerr << '\n';
#define vb vector<bool>
int mex(vb ar){
	for(int i = 0; i < ar.size(); i++){
		if(!ar[i]){
			return i;
		}
	}
	return ar.size();
}
int max_mex(int a, vi tree[], vb& is_vis, vi& values){
	if(tree[a].empty()){
		is_vis[values[a]] = 1;
		int ans = mex(is_vis);
		is_vis[values[a]] = 0;
		return ans;
	}
	is_vis[values[a]] = 1;
	int ans =  0;
	for(auto c : tree[a]){
		ans = max(ans, max_mex(c, tree, is_vis, values));
	}
	is_vis[values[a]] = 0;
	return ans ;
}
void make_tree(int r, vi tree[],vi edges[], int ances){
	for(auto c : edges[r]){
		if(c != ances){
			tree[r].push_back(c);
			make_tree(c, tree, edges, r);
		}
	}
}
void solve(){
	int n;
	cin >> n;
	vi values(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> values[i];
	}
	vi tree[n + 1];
	vi edges[n + 1];
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);

	}
	make_tree(1, tree, edges, -1);
	vb is_vis(n + 1, 0);
	cout << max_mex(1, tree, is_vis, values) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; 			// total number of text cases
	cin >> T;
	while(T--){
		solve();
	}
}