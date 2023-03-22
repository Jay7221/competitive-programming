#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> low(26), up(26);
	auto isUpperCase = [&](char ch){
		return ((ch >= 'A') && (ch <= 'Z'));
	};
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		if(isUpperCase(ch)){
			++up[ch - 'A'];
		}else{
			++low[ch - 'a'];
		}
	}
	int ans = 0, possible = 0;
	for(int i = 0; i < 26; ++i){
		ans += min(low[i], up[i]);
		possible += (max(low[i], up[i]) - min(low[i], up[i])) / 2;
	}
	ans += min(k, possible);
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
