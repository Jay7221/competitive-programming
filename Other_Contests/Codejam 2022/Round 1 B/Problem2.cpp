#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	int n, p;
	cin >> n >> p;
	vector<ll> cost(n), mx(n), mn(n);
	ull ans = 0;
	for(int i = 0; i < n; i++){
		vector<ll> prod(p);
		for(int j = 0; j < p; j++)
			cin >> prod[j];
		sort(prod.begin(), prod.end());
		mx[i] = prod[p - 1];
		mn[i] = prod[0];
		for(int j = 1; j < p; j++){
			cost[i] += prod[j] - prod[j - 1];
		}
		ans += cost[i];
	}
	vector<vector<ull> > dp(n, vector<ull>(2, 0));
	dp[0][1] = mn[0];
	dp[0][0] = mx[0];
	for(int i = 1; i < n; i++){
		dp[i][1] = min(dp[i - 1][1] + abs(mx[i - 1] - mn[i]), dp[i - 1][0] + abs(mn[i - 1] - mn[i]));
		dp[i][0] = min(dp[i - 1][1] + abs(mx[i - 1] - mx[i]), dp[i - 1][0] + abs(mn[i - 1] - mx[i]));
	}
	ans += min(dp[n - 1][1], dp[n - 1][0]);
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}