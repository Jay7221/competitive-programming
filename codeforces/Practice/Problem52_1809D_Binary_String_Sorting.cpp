#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll cost2 = 1e12;
	ll cost1 = cost2 + 1;
	string s;
	cin >> s;
	int n = s.size();
	int left[n][2], right[n][2];
	for(int i = 0; i < n; ++i){
		if(s[i] == '0'){
			left[i][0] = 1;
			right[i][0] = 1;
			left[i][1] = 0;
			right[i][1] = 0;
		}else{
			left[i][0] = 0;
			right[i][0] = 0;
			left[i][1] = 1;
			right[i][1] = 1;
		}
	}
	for(int i = 1; i < n; ++i){
		for(int k = 0; k < 2; ++k){
			left[i][k] += left[i - 1][k];
		}
	}
	for(int i = n - 2; i >= 0; --i){
		for(int k = 0; k < 2; ++k){
			right[i][k] += right[i + 1][k];
		}
	}
	ll ans = cost1 * min(right[0][0], left[n - 1][1]);
	for(int i = 0; i < n - 1; ++i){
		ll tmp = cost1 * (left[i][1] + right[i + 1][0]);
		if((s[i] == '1') && (s[i + 1] == '0')){
			tmp += cost2 - 2 * cost1;
		}
		ans = min(ans, tmp);
	}
	cout << ans << '\n';
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
