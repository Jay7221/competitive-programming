#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	vector<char> a(4);
	for(int i = 0; i < 4; ++i)
		cin >> a[i];
	vector<int> freq(26);
	for(int i = 0; i < 4; ++i)
		++freq[a[i] - 'a'];
	sort(freq.rbegin(), freq.rend());
	int ans = 0;
	for(int i = 1; i < 4; ++i){
		if(freq[i]){
			++ans;
		}
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}