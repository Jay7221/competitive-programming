#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n  >> m;
	vector<vector<bool> > g(n, vector<bool>(m, 0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char c;
			cin >> c;
			g[i][j] = (c == 'R');
		}
	}
	auto debug = [&](){
		for(auto c : g){
			for(auto k : c)
				cerr << k << ' ' ;
			cerr << '\n';
		}
		cerr << '\n';
	};
	bool pos = 1;
	int x, y;
	auto find = [&](){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(g[i][j]){
					x = j, y = i;
					return ;
				}
			}
		}
	};
	find();
	for(int j = 0; j < x; ++j){
		for(int i = 0; i < n; ++i){
			if(g[i][j]){
				pos = 0;
			}
		}
	}
	if(pos){
		cout << "YES\n";
		return ;
	}else{
		cout << "NO\n";
	}
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