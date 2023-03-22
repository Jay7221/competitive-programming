#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		for(char ch : s){
			x[i] ^= (1 << (ch - 'a'));
			y[i] |= (1 << (ch - 'a'));
		}
	}
	ll ans = 0;
	int super_mask = (1 << 26) - 1;
	for(int j = 0; j < 26; ++j){
		int mask = super_mask;
		mask ^= (1 << j);
		map<int, int> freq;
		for(int i = 0; i < n; ++i){
			if(!(y[i] & (1 << j))){
				ans += freq[mask ^ x[i]];
				++freq[x[i]];
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
