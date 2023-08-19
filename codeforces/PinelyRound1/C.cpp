#include<bits/stdc++.h>
using namespace std;
const int maxN = 101;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<bitset<100> > b(n), a(n);
	vector<vector<int> > graph(n);
	vector<int> in(n);
	for(int i = 0; i < n; ++i){
		a[i][i] = 1;
		for(int j = 0; j < n; ++j){
			char ch;
			cin >> ch;
			b[i][j] = (ch - '0');
			if(b[i][j]){
				graph[i].push_back(j);
				++in[j];
			}
		}
	}
	vector<int> q;
	for(int i = 0; i < n; ++i){
		if(in[i] == 0){
			q.push_back(i);
		}
	}
	while(q.size()){
		vector<int> qq;
		for(auto u : q){
			for(auto v : graph[u]){
				a[v] = (a[v] | a[u]);
				--in[v];
				if(in[v] == 0){
					qq.push_back(v);
				}
			}
		}
		q = qq;
	}
	for(int i = 0; i < n;++i){
		vector<int> v;
		for(int j = 0; j < n; ++j){
			if(a[i][j])
				v.push_back(j);
		}
		cout << v.size() << ' ';
		for(auto elem : v)
			cout << elem + 1 << ' ';
		cout << '\n';
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
	return 0;
}