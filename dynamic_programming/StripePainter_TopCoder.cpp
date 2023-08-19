#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';}cerr << '\n';
#define inf (int)(1e9 + 7)
class StripePainter{
public:
	int minStrokes(string s){
		int n = s.size();
		s.insert(s.begin(), '0');
		vector<vector<int> > dp(n + 2, vector<int>(n + 2));
		for(int i = 0; i < n + 1; ++i){
			dp[i][i] = 1;
		}
		// for(int k = 1; k < n; ++k){
		// 	for(int i = 1; i < n - k + 1; ++i){
		// 		dp[i][i + k] = dp[i][i + k - 1] + 1;
		// 		int tmp = 0, cur = i;
		// 		for(int j = i; j <= i + k; ++j){
		// 			if(s[j] == s[i + k]){
		// 				tmp += dp[cur][j - 1];
		// 				cur = j + 1;
		// 			}
		// 		}
		// 		if(dp[i][i + k] > tmp + 1){
		// 			dp[i][i + k] = tmp + 1;
		// 		}
		// 	}
		// }

		// basically dp[i][j] = dp[i][k] + dp[k + 1][j] - 1, if s[i] == s[j] or s[k] == s[k + 1], where i <= k < j;
		// else dp[i][j] = dp[i][k] + dp[k + 1][j]
		for(int k = 1; k < n; ++k){
			for(int i = 1; i < n - k + 1; ++i){
				dp[i][i + k] = inf;
				for(int j = i; j < i + k; ++j){
					if((s[i] == s[i + k]) || (s[j] == s[j + 1])){
						dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] - 1);
					}else{
						dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
					}
				}
			}
		}
		return dp[1][n];
	}
};
int main(){
	string s;
	StripePainter p;
	// cout << p.minStrokes(s) << '\n';
	while(cin >> s){
		cout << s << " : ";
		cout << p.minStrokes(s) << '\n';
	}
}