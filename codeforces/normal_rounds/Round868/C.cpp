#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	map<int, int> freq;
	auto process = [&](int x){
		int ans = 0;
		for(int i = 2; i * i <= x; ++i){
			while(x % i == 0){
				x /= i;
				++freq[i];
			}
		}
		if(x > 1){
			++freq[x];
		}
	};
	for(int elem : a){
		process(elem);
	}
	int ans = 0;
	int cnt = 0;
	for(auto [u, f] : freq){
		ans += f / 2;
		cnt += f % 2;
	}
	ans += cnt / 3;
	cout << ans << '\n';
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