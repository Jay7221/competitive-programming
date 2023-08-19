#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> weight(n);
	for(int i = 0; i < n; i++){
		cin >> weight[i];
	}
	vector<pair<int, int> > dp(1 << n, {n + 1, 0});
	dp[0] = {1, 0};
	for(int s = 1; s < (1 << n); s++){
		// dp[s] = {n + 1, 0};
		for(int p = 0; p < n; p++){
			if(s & (1 << p)){
				pair<int, int> without_p = dp[s ^ (1 << p)];
				if(without_p.second + weight[p] <= x){
					without_p.second += weight[p];
				}else{
					without_p.first++;
					without_p.second = weight[p];
				}
				dp[s] = min(dp[s], without_p);
			}
		}
	}
	cout << dp[(1 << n) - 1].first << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}