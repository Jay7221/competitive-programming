#include<iostream>
#include<vector>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<vector<int> > adj(n + 1);
	vector<bool> dp(n + 1);
	dp[0] = true;
	// dp[i] = 1 if and only if a[0 : i] is a valid message
	auto check = [&](int ind){
		if((ind > 0) && (ind <= n))
			return true;
		else
			return false;
	};
	for(int i = 1; i <= n; ++i){
		if(check(i + a[i])){
			adj[i].push_back(i + a[i]);
		}
		if(check(i - a[i])){
			adj[i - a[i]].push_back(i);
		}
	}
	for(int i = 1; i <= n; ++i){
		if(dp[i - 1]){
			for(auto r : adj[i])
				dp[r] = true;
		}
	}
	if(dp[n])
		cout << "YES\n";
	else
		cout << "NO\n";
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