#include<bits/stdc++.h>
using namespace std;
const int MAX = (1 << 30) - 1;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > tree(n + 2);
	vector<int> a(n + 2);
	auto proc = [&](int i){
		for(auto p : tree[i]){
			int v, x;
			tie(v, x) = p;
			a[i] = a[i] | x;
		}
		for(auto p : tree[i]){
			int v, x;
			tie(v, x) = p;
			a[i] = a[i] & x;
		}
	};
	while(m--){
		int i, j, x;
		cin >> i >> j >> x;
		tree[i].push_back({j, x});
		tree[j].push_back({i, x});
	}
	for(int i = 1; i <= n; ++i)
		proc(i);
	for(int i = 1; i <= n; ++i){
		int tmp = a[i];
		for(auto p : tree[i]){
			int j, x;
			tie(j, x) = p;
			if(i != j){
				tmp = tmp & a[j];
			}else{
				tmp = tmp & 0;
			}
		}
		a[i] = a[i] ^ tmp;
	}
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ' ;
	cout << '\n';
}