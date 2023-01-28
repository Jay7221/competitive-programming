#include<bits/stdc++.h>
using namespace std;
#define ll long long
class DSU{
private:
	int s;
	vector<int> parent;
	vector<int> size;
public :
	DSU(int n);
	int find(int u);
	void merge(int u, int v);
};
DSU::DSU(int n){
	s = n + 1;
	parent.resize(s);
	size.resize(s);
	for(int i = 0; i < s; i++){
		size[i] = 1;
		parent[i] = i;
	}
}
int DSU::find(int u){
	stack<int> nodes;
	while(parent[u] != u){
		nodes.push(u);
		u = parent[u];
	}
	while(!nodes.empty()){
		parent[nodes.top()] = u;
		nodes.pop();
	}
	return u;
}
void DSU::merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v)
		return ;
	if(size[u] > size[v])
		swap(u, v);
	parent[u] = v;
	size[u] += size[v];
}
void solve(){
	int n, m;
	cin >> n >> m;
	DSU city(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		city.merge(a, b);
	}
	vector<pair<int, int> > to_do;
	for(int i = 2; i < n + 1; i++){
		if(city.find(i - 1) != city.find(i)){
			city.merge(i - 1, i);
			to_do.push_back({i - 1, i});
		}
	}
	cout << to_do.size() << '\n';
	for(auto c : to_do){
		cout << c.first << ' ' << c.second << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}