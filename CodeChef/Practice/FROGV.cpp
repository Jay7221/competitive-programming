#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
struct dsu{
	vector<int> par;
	vector<int> size;
	int n;
	dsu(int num){
		n = num;
		par.clear();
		size.clear();
		size.resize(n + 1);
		par.resize(n + 1);
		for(int i = 0; i < n + 1; i++){
			size[i] = 1;
			par[i] = i;
		}
	}
	int get_par(int u){
		if(par[u] == u)
			return u;
		return par[u] = get_par(par[u]);
	}
	void merge(int a, int b){
		a = get_par(a), b = get_par(b);
		if(a == b)
			return ;
		if(size[b] > size[a])
			swap(a, b);
		par[b] = a;
		size[a] += size[b];
	}
};
void solve(){
	int n, k, p;
	cin >> n >> k >> p;
	map<int, vector<int> > coords;
	for(int i = 1; i < n + 1; i++){
		int x;
		cin >> x;
		coords[x].push_back(i);
	}
	dsu frogs(n);
	int prev = -1, prev_coords = -1;
	for(auto c : coords){
		int a = c.first;
		for(auto k : c.second){
			frogs.merge(k, c.second.back());
		}
		if(prev != -1){
			if(k >= a - prev_coords){
				frogs.merge(prev, c.second.back());
			}
		}
		prev = c.second.back(), prev_coords = a;
	}
	for(int i = 0; i < p; i++){
		int u, v;
		cin >> u >> v;
		if(frogs.get_par(u) == frogs.get_par(v)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}