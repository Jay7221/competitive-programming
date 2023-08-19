#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, p, k;
	cin >> n >> p >> k;
	int m;
	vector<int> a(m);
	for(int i = 0; i < m; ++i){
		cin >> a[i];
	}
	int dp[30][k][2];
	for(int i = 0; i < min(p + 1, k); ++i){
		dp[0][i][0] = (p - i) / k + 1;
	}
	dp[0][0][0] -= 1;
	
}