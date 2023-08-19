#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vf vector<double>
#define vb vector<bool>
#define vii std::vector<vi> 
#define max_n (int)(1e5)
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
#define end_case cerr<< "----------------------------------------------------------\n";
vi is_vis(max_n + 5, 0);
vi val(max_n + 5);
int ans = 0;
int n = 0;
void dfs(vii edg, int a, int p = -1, int mex = 0){
	is_vis[val[a]]++;
	while(is_vis[mex]){
		mex++;
	}
	// cerr << a << ' ' << mex << '\n';
	// debug(is_vis, n + 1)
	ans = max(ans, mex);
	for(auto c : edg[a]){
		if(c != p){
			dfs(edg, c, a, mex);
		}
	}
	is_vis[val[a]]--;
	return ;
}
void solve(){
	cin >> n;
	vii edg(n + 1, vi(0));
	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}
	for(int i = 1; i <= n - 1; i++){
		int x, y;
		cin >> x >> y;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	ans = 0;
	dfs(edg, 1);
	cout << ans << '\n';
	// end_case
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}