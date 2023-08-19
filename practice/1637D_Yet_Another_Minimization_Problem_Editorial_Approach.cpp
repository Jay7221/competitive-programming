#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(1e4 + 7)
void solve(){
	int n;
	cin >> n;
	auto sqr = [&](int n){
		return n * n;
	};
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		if(a[i] > b[i])
			swap(a[i], b[i]);
	}
	int sumMax = 0, sumMin = 0, sumSqr = 0;
	for(int i = 0; i < n; ++i){
		sumMax += b[i];
		sumMin += a[i];
		sumSqr += sqr(a[i]) + sqr(b[i]);
	}
	bitset<mx> dp;
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		dp |= (dp << (b[i] - a[i]));
	}
	int ans = sqr(sumMax) + sqr(sumMin);
	for(int i = 0; i < sumMax - sumMin; i++){
		if(dp[i]){
			ans = min(ans, sqr(sumMax - i) + sqr(sumMin + i));
		}
	}
	cout << ans + (n - 2) * sumSqr << '\n';
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
}