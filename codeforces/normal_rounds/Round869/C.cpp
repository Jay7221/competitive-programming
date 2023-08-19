#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> dp(n);
	auto check = [&](int x, int y, int z){
		return ((a[x] >= a[y]) && (a[y] >= a[z]));
	};
	for(int i = 2; i < n; ++i){
		dp[i] = dp[i - 1];
		if(check(i - 2, i - 1, i)){
			++dp[i];
		}
	}
	auto query = [&](int l, int r){
		int ans = r - l + 1;
		if(ans > 2){
			ans = 2 + (r - l - 1 - (dp[r] - dp[l + 1]));
		}
		return ans;
	};
	while(q--){
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << query(l, r) << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
	
	return 0;
}