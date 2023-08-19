#include<bits/stdc++.h>
using namespace std;
class BadNeighbors{
public:
	int maxDonations(vector<int>& a){
		int n = a.size();
		vector<vector<int> > dp(n, vector<int>(2));
		dp[0][1] = 0;
		for(int i = 1; i < n; ++i){
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		int ans = max(dp[n - 1][1], dp[n - 1][0]);
		dp[0][1] = a[0];
		a[1] = 0;
		for(int i = 1; i < n; ++i){
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		ans = max(ans, max(dp[n - 2][0], dp[n - 2][1]));
		return ans;
	}
};
int main(){
	vector<int> a;
	int k;
	while(cin >> k){
		a.push_back(k);
		char ch;
		cin >> ch;
	}
	BadNeighbors s;
	cout << s.maxDonations(a) << '\n';
}