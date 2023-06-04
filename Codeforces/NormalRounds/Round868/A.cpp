#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	auto get = [&](int cnt){
		int alt_cnt = n - cnt;
		int ans = (cnt * (cnt - 1)) / 2 + (alt_cnt * (alt_cnt - 1)) / 2;
		return ans;
	};
	auto answer = [&](int p){
		cout << "YES\n";
		for(int i = 0; i < p; ++i){
			cout << 1 << ' ';
		}
		for(int i = p; i < n; ++i){
			cout << -1 << ' ';
		}
		cout << '\n';
	};
	for(int i = 0; i <= n; ++i){
		if(get(i) == k){
			answer(i);
			return;
		}
	}
	cout << "NO" << '\n';
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