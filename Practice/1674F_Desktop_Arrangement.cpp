#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx (int)(1e6 + 7)
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	bitset<mx> mp;
	int cur = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			cur += (c == '*');
			mp[i + j * n] = (c == '*');
		}
	}
	int tmp = 0;
	for(int i = 0; i < cur; i++){
		tmp += mp[i];
	}
	auto debug = [&](){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cerr << mp[i + j * n] << ' ' ;
			cerr << '\n';
		}
		cerr << '\n';
	};
	int ans = cur - tmp;
	while(q--){
		int i, j;
		cin >> i >> j;
		--i, --j;
		mp[i + j * n] = (mp[i + j * n] ^ 1);
		if(mp[i + j * n]){
			cur++;
			if(i + j * n >= cur - 1){
				ans++;
			}
			if(mp[cur - 1]){
				ans--;
			}
		}else{
			cur--;
			if(i + j * n > cur){
				ans--;
			}
			if(mp[cur])
				ans++;
		}
		cout << ans << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}