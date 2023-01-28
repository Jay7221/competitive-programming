#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ; } cerr << '\n';
vector<vector<int> > board;
int dp[30][30][30][30];
int dp2[30][30][30][30];
int check(int l1, int l2, int r1, int r2){
	if(dp2[l1][l2][r1][r2] != -1)
		return dp2[l1][l2][r1][r2];
	int ans;
	int k = board[l1][r1];
	if(k != 2 && k != 3 && k != 5 && k != 7){
		ans = 1;
	}else{
		ans = 0;
	}
	if(l1 != l2){
		if(check(l1, l2 - 1, r1, r2) || check(l2, l2, r1, r2))
			ans = 1;
	}
	if(r1 != r2){
		if(check(l1, l2, r1, r2 - 1) || check(l1, l2, r2, r2))
			ans = 1;
	}
	return dp2[l1][l2][r1][r2] = ans;
}
int gurdy(int l1, int l2, int r1, int r2){
	if(dp[l1][l2][r1][r2] != -1)
		return dp[l1][l2][r1][r2];
	int ans = 0;
	vector<int> tmp;
	for(int l = l1; l < l2; ++l){
		tmp.push_back(gurdy(l1, l, r1, r2) ^ gurdy(l + 1, l2, r1, r2));
	}
	for(int r = r1; r < r2; ++r){
		tmp.push_back(gurdy(l1, l2, r1, r) ^ gurdy(l1, l2, r + 1, r2));
	}
	sort(tmp.begin(), tmp.end());
	if(check(l1, l2, r1, r2)){
		for(auto c : tmp){
			if(ans == c)
				++ans;
		}
	}
	return dp[l1][l2][r1][r2] = ans;
}
void solve(){
	int n; 
	cin >> n;
	board.clear();
	board.resize(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cin >> board[i][j];
	}
	for(int l1 = 0; l1 < n; ++l1){
		for(int l2 = 0; l2 < n; ++l2){
			for(int r1 = 0; r1 < n; ++r1){
				for(int r2 = 0; r2 < n; ++r2){
					dp[l1][l2][r1][r2] = -1;
					dp2[l1][l2][r1][r2] = -1;
				}
			}
		}
	}
	if(gurdy(0, n - 1, 0, n - 1)){
		cout << "First\n";
	}else{
		cout << "Second\n";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}