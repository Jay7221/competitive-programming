#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
vector<int> W, backlink;
vector<vector<int> > dp;
int solve(int s, int k){
	if(s == 0)
		return 1;
	if( (s < 0) || (k < 0))
		return 0;
	if(dp[s][k])
		return dp[s][k];
	for(int i = 0; i < k + 1; ++i){
		if(solve(s - W[i], i - 1)){
			dp[s][k] = 1;
			backlink[s] = W[i];
			return 1;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	prep(W)
	for(int i = 0; i < n; ++i)
		cin >> W[i];
	int k;
	cin >> k;
	while(k--){
		int s;
		backlink.clear();
		backlink.resize(s + 10, 0);
		cin >> s;
		dp.clear();
		dp.resize(s + 10, vector<int>(n));
		solve(s, n - 1);
		if(solve(s, n - 1)){
			vector<int> ans;
			while(s){
				ans.push_back(backlink[s]);
				s -= backlink[s];
			}
			for(auto c : ans){
				cout <<  c << ' ';
			}
			cout << '\n';
		}else{
			cout << -1 << '\n';
		}
	}
}