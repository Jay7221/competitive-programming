#include<bits/stdc++.h>
using namespace std;
#define inf (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
class ShortPalindromes{
public:
	string shortest(string base){
		int n = base.size();
		vector<string> s(n + 1);
		for(int i = 1; i < n + 1; ++i){
			s[i] += base[i - 1];
		}
		vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
		vector<vector<string> > backlink(n + 1, vector<string>(n + 1));
		for(int i = 1; i < n + 1; ++i){
			dp[i][i] = 0;
			backlink[i][i] = s[i];
		}
		for(int k = 1; k < n ; ++k){
			for(int i = 1; i + k < n + 1; ++i){
				int j = i + k;
				if(s[i] == s[j]){
					dp[i][j] = dp[i + 1][j - 1];
					backlink[i][j] = s[i] + backlink[i + 1][j - 1] + s[j];
				}
				else if(dp[i][j - 1] < dp[i + 1][j]){
					dp[i][j] = dp[i][j - 1] + 1;
					backlink[i][j] = s[j] + backlink[i][j - 1] + s[j];
				}
				else{
					dp[i][j] = dp[i + 1][j] + 1;
					backlink[i][j] = s[i] + backlink[i + 1][j] + s[i];
				}
			}
		}
		return backlink[1][n];
	}
};
int main(){
	ShortPalindromes p;
	cerr << p.shortest("ALRCAGOEUAOEURGCOEUOOIGFA") << '\n';
}