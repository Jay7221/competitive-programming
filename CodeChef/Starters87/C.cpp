#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; ++i){
		cin >> p[i];
		--p[i];
	}
	vector<int> left(n, -1), right(n, n + 1);
	for(int i = 1; i < n; ++i){
		left[i] = max(left[i - 1], p[i - 1]);
	}
	for(int i = n - 2; i >= 0; --i){
		right[i] = min(right[i + 1], p[i + 1]);
	}
	int cur = 0;
	for(int i = 0; i < n; ++i){
		if((left[i] < p[i]) && (p[i] < right[i])){
			++cur;
		}
	}
	int ans = 1;
	for(int i = 0; i < cur; ++i){
		ans = (ans * 2) % MOD;
	}
	if(cur == n){
		--ans;
	}
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