#include <bits/stdc++.h>
using namespace std;
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ';} cerr << '\n';
#define vi vector<int>
void solve(){
	int n, m;
	cin >> n >> m;
	vi a(n);
	int max_m = 0, min_m = 1e8;
	int k;
	for(int i = 0; i < m; i++){
		cin >> k;
		max_m = max(k, max_m);
		min_m = min(k, min_m);
	}
	for(int i = 0; i < n; i++){
		a[i] = max(abs(i - max_m), abs(i - min_m));
	}
	for(auto c : a){
		cout << c << ' ';
	}
	cout << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}