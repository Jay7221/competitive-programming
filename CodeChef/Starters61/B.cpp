#include<iostream>
#include<vector>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<long long> a(n + 2), dp1(n + 2), dp2(n + 2);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i){
		dp1[i] = 1;
		if(a[i] < a[i - 1]){
			dp1[i] = dp1[i - 1] + 1;
		}
	}
	for(int i = n; i > 0; --i){
		dp2[i] = 1;
		if(a[i] < a[i + 1]){
			dp2[i] = dp2[i + 1] + 1;
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += (dp1[i] * dp2[i]);
	cout << ans << '\n';
	return ;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
