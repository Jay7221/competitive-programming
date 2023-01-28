#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(1e5 + 10)
void solve(){
	int n;
	cin >> n;
	vector<int> coins(n + 1);
	for(int i = 1;i < n + 1; i++)
		cin >> coins[i];
	vector<vector<int> > possible(n + 1, vector<int>(mx, 0));
	for(int i = 0; i < n + 1; i++)
		possible[i][0] = 1;
	for(int i = 1; i < n + 1; i++){
		for(int j = 0; j < mx; j++){
			possible[i][j] = possible[i - 1][j];
			if(j - coins[i] >= 0){
				possible[i][j] = (possible[i][j] | possible[i - 1][j - coins[i]]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < mx; i++){
		if(possible[n][i])
			ans++;
	}
	cout << ans << '\n';
	for(int i = 1; i < mx; i++){
		if(possible[n][i])
			cout << i << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}