#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	map<int, int> freq;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		++freq[a];
	}
	int ans = 0;
	for(auto [u, f] : freq){
		ans = max(ans, f);
	}
	cout << (n - ans) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}