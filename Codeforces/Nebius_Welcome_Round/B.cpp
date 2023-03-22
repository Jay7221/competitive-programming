#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k, d, w;
	cin >> n >> k >> d >> w;
	vector<int> t(n);
	for(int i = 0; i < n; ++i){
		cin >> t[i];
	}
	int ans = 0;
	int exp_time = -1, no_doses = 0;
	for(int i = 0; i < n; ++i){
		if((exp_time < t[i]) || (no_doses <= 0)){
			no_doses = k;
			exp_time = t[i] + w + d;
			++ans;
		}
		--no_doses;
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
