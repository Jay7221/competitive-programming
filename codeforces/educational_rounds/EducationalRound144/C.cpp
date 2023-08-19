#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
int add(int a, int b){
	ll aa = a, bb = b;
	return ((aa + bb) % MOD);
}
int sub(int a, int b){
	ll aa = a, bb = b;
	return ((aa - bb + MOD) % MOD);
}
int getK(int l, int r){
	int cur = l;
	int k = 1;
	while(2 * cur <= r){
		cur *= 2;
		++k;
	}
	return k;
}
const int MAX_A = 1e6 + 7;
const int MAX_S = 21;
int dp[MAX_A][MAX_S];
void pre(){
	for(int i = 1; i < MAX_A; ++i){
		dp[i][1] = 1;
	}
	for(int i = 1; i < MAX_A; ++i){
		for(int k = MAX_S - 2; k > 0; --k){
			if(dp[i][k]){
				for(int j = 2; i * j < MAX_A; ++j){
					dp[i * j][k + 1] =  (dp[i][k] + dp[i * j][k + 1]) % MOD;
				}
			}
		}
	}
	for(int i = 1; i < MAX_A; ++i){
		for(int k = MAX_S - 2; k > 0; --k){
			dp[i][k] = add(dp[i][k], dp[i - 1][k]);
		}
	}
}
void solve(){
	int l, r;
	cin >> l >> r;
	int k = getK(l, r);
	cout << k << ' ' << ( -l + ( r /  (int)pow(2, k - 1)) + 1)<< '\n';
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
