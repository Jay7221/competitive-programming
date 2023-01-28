#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto get = [&](int ind){
		ll ans = 0;
		vector<int> freq(10);
		int distinct = 0;
		int mx = 0;
		for(int i = ind; i < min(n, ind + 100); ++i){
			int a = s[i] - '0';
			if(freq[a] == 0){
				++distinct;
			}
			++freq[a];
			mx = max(mx, freq[a]);
			if(mx <= distinct)
				++ans;
		}
		return ans;
	};
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans += get(i);
	}
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