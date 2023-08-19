#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	map<int, int> freq;
	int odd_count = 0;
	for(int i = 0; i < 2 * n; i++){
		int a;
		cin >> a;
		freq[a]++;
		odd_count += a % 2;
	}
	if(odd_count != n){
		cout << 0 << '\n';
		return ;
	}
	vector<int> P;
	ll sum = 0;
	for(auto c : freq){
		int a = c.first;
		if(a % 2 == 0)
			continue ;
		if(freq[a] != freq[a + 1]){
			cout << 0 << '\n';
			return ;
		}
		sum += a * c.second;
		P.push_back(c.second);
	}
	int m = P.size();
	int d = k - sum ;
	if(d < 0 || d > n){
		cout << 0 << '\n';
		return ;
	}
	// now find x1 + x2 + x3 + ... + xm = d, such that 0 <= x1 <= p1, 0 <= x2 <= p2, ... , 0 <= xm <= pm
	vector<vector<ll> > dp(m, vector<ll>(d + 1, 0));
	for(int s = 0; s < P[0] + 1; s++){
		dp[0][s] = 1;
	}
	for(int i = 1; i < m; i++){
		for(int s = 0; s < d + 1; s++){
			for(int t = 0; t < P[i] + 1; t++){
				if(s - t > -1){
					dp[i][s] += dp[i - 1][s - t];
					dp[i][s] %= mod;
				}
			}
		}
	}
	cout << dp[m - 1][d] << '\n';
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