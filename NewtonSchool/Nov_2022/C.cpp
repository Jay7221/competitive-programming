#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
void solve(){
	int n;
	cin >> n;
	auto add = [&](ll a, ll b){
		return (a + b) % MOD;
	};
	auto mult = [&](ll a, ll b){
		return (a * b) % MOD;
	};
	vector<map<int, int> > freq(3);
	vector<int> a(n + 1), b(n + 1), c(n + 1);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	int dp[n + 1][n + 1][n + 1];
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= n; ++j){
			for(int k = 0; k <= n; ++k)
				dp[i][j][k] = 0;
		}
	}
	for(int i = 1; i <= n; ++i){
		freq[1].clear();
		for(int j = 1; j <= n; ++j){
			freq[2].clear();
			for(int k = 1; k <= n; ++k){
				if((a[i] == b[j]) && (b[j] == c[k])){
					int x = freq[0][a[i]];
					int y = freq[1][a[i]];
					int z = freq[2][a[i]];
					dp[i][j][k] = add(1ll, dp[i - 1][j - 1][k - 1]);
					dp[i][j][k] = add(dp[i][j][k], dp[i][j][k]);
					dp[i][j][k] = add(dp[i][j][k], dp[i][j][z]);
					dp[i][j][k] = add(dp[i][j][k], dp[i][y][k]);
					dp[i][j][k] = add(dp[i][j][k], dp[i][y][z]);
					dp[i][j][k] = add(dp[i][j][k], dp[x][j][k]);
					dp[i][j][k] = add(dp[i][j][k], dp[x][j][z]);
					dp[i][j][k] = add(dp[i][j][k], dp[x][y][k]);
					dp[i][j][k] = add(dp[i][j][k], dp[x][y][z]);
				}else{
					set<int> s;
					s.insert(a[i]);
					s.insert(b[j]);
					s.insert(c[k]);
					if((a[i] != b[j]) && (a[i] != c[k]) && (b[j] != c[k])){
						dp[i][j][k] = add(dp[i][j][k], dp[i][freq[1][a[i]]][freq[2][a[i]]]);
						dp[i][j][k] = add(dp[i][j][k], dp[freq[0][b[j]]][j][freq[2][b[j]]]);
						dp[i][j][k] = add(dp[i][j][k], dp[freq[0][c[k]]][freq[1][c[k]]][k]);
					}
				}
				freq[2][c[k]] = k;
			}
			freq[1][b[j]] = j;
		}
		freq[0][a[i]] = i;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				cerr << i << ' ' << j << ' ' << k << " : " << dp[i][j][k] << '\n';
			}
		}
	}
	cout << dp[n][n][n] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}