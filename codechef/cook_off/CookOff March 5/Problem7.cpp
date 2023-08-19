#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vp vector<pair<int, int>>
bool communicate(int a, int b, int c){
	cout << "? 3 " << a << ' ' << b << ' ' << c << '\n';
	bool t;
	cin >> t;
	return t;
}
void find_edges(vi& a, vp& edges){
	int n = a.size();
	if(n == 1){
		return ;
	}
	if(n == 2){
		edges.push_back({a[0], a[1]});
		return ;
	}
	int p = a[0], q = a[1];
	for(auto c : a){
		if(c == p || c == q){
			continue ;
		}
		if(communicate(p, c, q)){
			q = c;
		}
	}
	edges.push_back({p, q});
	vi left, right;
	left.push_back(p);
	right.push_back(q);
	for(auto c : a){
		if(c == p || c == q){
			continue ;
		}
		if(communicate(p, q, c)){
			right.push_back(c);
		}
		else{
			left.push_back(c);
		}
	}
	find_edges(right, edges);
	find_edges(left, edges);
}
void solve(){
	int N;
	cin >> N;
	vi a(N);
	iota(a.begin(), a.end(), 1);
	vp edges;
	find_edges(a, edges);
	cout << "!" << '\n';
	for(auto x : edges){
		cout << x.first << ' ' << x.second << '\n';
	}
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while(T--){
		solve();
	}
	return 0;
}
