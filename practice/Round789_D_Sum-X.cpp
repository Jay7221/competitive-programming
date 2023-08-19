#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sub cerr << i << ' ' << j << " : " << g[i][j] << '\n';
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > g(n, vector<int>(m)), p, q;
	for(int i = 0; i  < n; i++){
		for(int j = 0; j < m;j++)
			cin >> g[i][j];
	}
	auto debug = [&](vector<vector<int> >&g){
		for(auto c  :g){
			for(auto k : c)
				cerr << k << ' ';
			cerr << '\n';
		}
		cerr << '\n';

	};
	p = g;
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			p[i][j] += p[i - 1][j - 1];
		}
	}
	for(int i = n - 2; i > -1; --i){
		for(int j = m - 2;j > -1; --j){
			p[i][j] = p[i + 1][j + 1];
		}
	}
	q = p;
	p = g;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < m - 1; ++j){
			p[i][j] += p[i - 1][j + 1];
		}
	}
	for(int i = n - 2; i > -1; --i){
		for(int j = 1; j < m; ++j){
			p[i][j] = p[i + 1][j - 1];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			ans = max(ans, p[i][j] + q[i][j] - g[i][j]);
		}
	}
	cout << ans << '\n';
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
}