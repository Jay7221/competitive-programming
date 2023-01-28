#include<iostream>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll preOne[n], preZero[n];
	ll zeros = 0, ones = 0;
	for(int i = 0; i < n; ++i){
		preOne[i] = (s[i] == '1');
		preZero[i] = (s[i] == '0');
		zeros += (s[i] == '0');
		ones += (s[i] == '1');
	}
	ll mx = max(preOne[0], preZero[0]);
	for(int i = 1; i < n; ++i){
		if(preOne[i]){
			preOne[i] += preOne[i - 1];
			mx = max(mx, preOne[i]);
		}
		if(preZero[i]){
			preZero[i] += preZero[i - 1];
			mx = max(mx, preZero[i]);
		}
	}
	ll ans = max(mx * mx, zeros * ones);
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}