#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
vl parent(1e7);
vl size__(1e7);
void make_set(ll v){
	parent[v] = v;
	size__[v] = 1;
}
int find_set(ll v){
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_sets(ll a, ll b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		if(size__[a] < size__[b])
			swap(a, b);
		parent[b] = a;
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	string data[n];
	for(int i = 0; i < n; i++){
		cin >> data[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			make_set(i * m + j);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(data[i][j] == '0')
				continue ;
			if(i > 0){
				if(data[i - 1][j] == data[i][j])
					union_sets(i * m + j, (i - 1) * m + (j));
			}
			if(j > 0){
				if(data[i][j - 1] == data[i][j])
					union_sets(i * m + j, (i) * m + (j - 1));
			}
			if(j < n - 1){
				if(data[i][j + 1] == data[i][j])
					union_sets(i * m + j, (i) * m + (j + 1));
			}
			if(i < n - 1){
				if(data[i + 1][j] == data[i][j])
					union_sets(i * m + j, (i + 1) * m + (j));
			}
		}
	}
	map<int, int> islands;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(data[i][j] == '1')
				islands[parent[i * m + j]]++;
		}
	}
	vi land;
	for(auto c : islands){
		land.push_back(c.second);
	}
	sort(land.begin(), land.end());
	ll ans = 0;
	for(int i = 1; i < land.size(); i += 2){
		ans += land[i];
	}
	cout << ans << '\n';


}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}