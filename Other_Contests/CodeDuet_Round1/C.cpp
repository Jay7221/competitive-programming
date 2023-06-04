#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> pre(n, vector<int>(26));
	for(int i = 0; i < n; ++i){
		++pre[i][s[i] - 'a'];
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < 26; ++j){
			pre[i][j] += pre[i - 1][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int mx = 0, mn = n + 1;
			for(int k = 0; k < 26; ++k){
				int freq = pre[j][k];
				if(i > 0){
					freq -= pre[i - 1][k];
				}
				if(freq > 0){
					mx = max(mx, freq);
					mn = min(mn, freq);
				}
			}
			ans += (mx - mn);
		}
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
