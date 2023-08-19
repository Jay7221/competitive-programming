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
bool union_sets(ll a, ll b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		if(size__[a] < size__[b])
			swap(a, b);
		parent[b] = a;
		return 1;
	}
	return 0;
}
void solve(){
	int n, q;
	cin >> n >> q;
	for(int i = 1; i < n + 1; i++){
		make_set(i);
	}
	int no_sets = n;
	for(int i = 1; i <= q; i++){
		int t;
		cin >> t;
		int a, b;
		switch(t){
			case 1:
				cin >> a >> b;
				if(union_sets(a, b))
					no_sets--;
				break;
			case 2:
				cin >> a >> b;
				if(find_set(a) == find_set(b)){
					cout << "YES" << '\n';
				}
				else{
					cout << "NO" << '\n';
				}
				break;
			case 3:
				cout << no_sets << '\n';
				break;
		}
	}
}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}