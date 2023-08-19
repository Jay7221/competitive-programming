#include<bits/stdc++.h>
using namespace std;
#define mx (int)(107)
#define inf (int)(1e9 + 7)
class QuickSums{
public:
	int minSums(string nums, int sum){
		int n = nums.size();
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			a[i] = nums[i] - '0';
		vector<vector<vector<vector<bool> > > > dp(n + 1, vector<vector<vector<bool> > >(mx, vector<vector<bool> >(10, vector<bool>(10))));
		dp[n - 1][a[n - 1]][1][0] = 1;
		dp[n - 1][a[n - 1]][0][1] = 1;
		for(int i = n - 2; i > -1; --i){
			for(int s = 0; s < mx; ++s){
				for(int p = 0; p < 10; ++p){
					for(int k = 0; k < 10; ++k){
						if(dp[i + 1][s][p][k]){
							if(s + a[i] * pow(10, p) < mx){
								dp[i][s + a[i] * pow(10, p)][p + 1][k] = 1;
								dp[i][s + a[i] * pow(10, p)][0][k + 1] = 1;

							}
						}
					}
				}
			}
		}


		// for(int i = n - 1; i > -1; --i){
		// 	cerr << i << " : ";
		// 	for(int s = 0; s < mx; ++s){
		// 		for(int p = 0; p < 10; ++p){
		// 			for(int k = 0; k < 10; ++k){
		// 				if(dp[i][s][p][k]){
		// 					cerr << "(" << s << ", " << p << ", " << k  << "), ";
		// 				}
		// 			}
		// 		}
		// 	}
		// 	cerr << '\n';
		// }

		int ans = inf;
		for(int p = 0; p < 10; ++p){
			for(int k = 0; k < 10; ++k){
				if(dp[0][sum][p][k])
					ans = min(ans, k);
			}
		}
		if(ans == inf)
			return -1;
		return ans;
	}
};
int main(){
	QuickSums q;
	string s = "9230560001";
	cout << q.minSums(s, 71) << '\n';
}