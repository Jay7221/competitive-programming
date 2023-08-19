#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define MAX (int)(1e6 + 3)
vector<ll> dp1(MAX);
// no of ways with ith block having width 2
vector<ll> dp2(MAX);
// no of ways with ith block having width 1
void pre(){
	dp1[1] = 1, dp2[1] = 1;
	for(int i = 2; i < MAX; i++){
		dp1[i] = 2 * dp1[i - 1] + dp2[i - 1];
		dp2[i] = dp1[i - 1] + 4 * dp2[i - 1];
		dp1[i] %= mod;
		dp2[i] %= mod;
	}
}
void solve(){
	int n;
	cin >> n;
	cout << ((dp1[n] + dp2[n]) % mod ) << '\n';
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