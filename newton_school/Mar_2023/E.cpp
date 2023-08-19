#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int m = s.size();
	int dp[m + 1][2][n + 1][2];
	for(int index = m - 1; index >= 0; --index){
		for(int xsum = 0; xsum <= 1; ++xsum){
			for(int numelem = 1; numelem <= n; ++numelem){
				for(int tight = 0; tight < 2; ++tight){

				}
			}
		}
	}
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

	return 0;
}
