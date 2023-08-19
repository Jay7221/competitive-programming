#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int> > freq(26, vector<int>(n + 1));
	for(int i = 1; i <= n; ++i){
		freq[s[i - 1] - 'a'][i] = 1;
	}
	for(int ch = 0; ch < 26; ++ch){
		for(int i = 1; i <= n; ++i){
			freq[ch][i] += freq[ch][i - 1];
		}
	}
	int q;
	cin >> q;
	int ans = 0;
	while(q--){
		int l, r;
		cin >> l >> r;
		if((r - l + 1) % 2 == 0)
			continue;
		int mid = (r - l + 1) / 2 + l;
		int tmp = 0;
		for(int ch = 0; ch < 26; ++ch){
			int first = freq[ch][mid] - freq[ch][l - 1];
			int last = freq[ch][r] - freq[ch][mid];
			if(last != first){
				++tmp;
			}
		}
		if(tmp == 1){
			++ans;
			continue ;
		}
		tmp = 0;
		--mid;
		for(int ch = 0; ch < 26; ++ch){
			int first = freq[ch][mid] - freq[ch][l - 1];
			int last = freq[ch][r] - freq[ch][mid];
			if(last != first){
				++tmp;
			}
		}
		if(tmp == 1){
			++ans;
		}
	}
	cout << ans << '\n';

}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}