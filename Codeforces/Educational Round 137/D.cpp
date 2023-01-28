#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
string s, ans, b;
int n;
void calc(int x){
	b = s;
	for(int i = x; i < n; ++i){
		b[i] = ((b[i] - '0') | (s[i - x] - '0')) + '0';
	}
	if(ans < b)
		ans = b;
}
void solve(){
	cin >> n;
	cin >> s;
	ans = s, b = s;
	for(int i = 1; i < min(50, n); ++i)
		calc(i);
	int k1 = n - 1;
	for(int i = n - 1; i > -1; --i){
		if(s[i] == '1')
			k1 = i;
	}
	ans = ans.substr(k1, n);
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}