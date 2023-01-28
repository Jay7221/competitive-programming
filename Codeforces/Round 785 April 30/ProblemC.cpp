#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define mx (ll)(40000 + 777)
vector<ll> palindromes;
vector<ll> dp(mx);
void pre(){
	palindromes.reserve(1170);
	for(int i = 1; i < 10; i++){
		palindromes.push_back(i);
	}
	for(int i = 1; i < 10; i++){
		palindromes.push_back(i + i * 10);
	}
	for(int i = 1; i < 10; i++){
		for(int j = 0; j < 10; j++){
			palindromes.push_back(i + i * 100 + 10 * j);
		}
	}
	for(int i = 1; i < 10; i++){
		for(int j = 0; j < 10; j++){
			palindromes.push_back(i + i * 1000 + j * 10 + j * 100);
		}
	}
	for(int i = 1; i < 10; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 10; k++){
				palindromes.push_back(i + i * 10000 + j * 10 + j * 1000 + k * 100);
			}
		}
	}
	dp[0] = 1;
	for(auto p : palindromes){
		for(int i = 0; i < mx; i++){
			if(p + i < mx){
				dp[i + p] += dp[i];
				dp[i + p] %= mod;
			}
		}
	}
}
void solve(){
	int n;
	cin >> n;
	cout << dp[n] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}