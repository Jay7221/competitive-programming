#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	string a = s;
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += (s[i] != a[i]);
	}
	ans /= 2;

	//----------------------------------------------------------------------



	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		if(s[i] == a[i])
			v[i] = -1;
		else
			v[i] = 1;
	}
	int zm = -1, om = n;
	for(int i = 0; i < n; ++i){
		if(a[i] == 0)
			zm = max(zm, i);
		else
			om = min(om, i);
	}
	for(int i = 1; i < zm + 1; ++i){
		v[i] += v[i - 1];
	}
	for(int i = n - 2; i > om - 1; --i){
		v[i] += v[i + 1];
	}
	int mx = 0;
	for(int i = om; i < n; ++i)
		mx = max(mx, v[i]);
	int sz = 0;
	for(int i = om; i < n; ++i){
		if(v[i] == mx){
			sz = i - om + 1;
			break ;
		}
	}
	int tmp = 0;
	if(sz <= zm + 1){
		tmp = mx + v[sz - 1];
		for(int i = sz; i < zm + 1; ++i){
			tmp = max(tmp, mx + v[i] - v[i - sz]);
		}
	}
	ans = min(ans, ans - tmp);



	mx = 0;
	for(int i = zm; i > -1; --i)
		mx = max(mx, v[i]);
	sz = 0;
	for(int i = zm; i > -1; --i){
		if(v[i] == mx){
			sz = i + 1;
			break ;
		}
	}
	tmp = 0;
	if(om + sz < n + 1){
		tmp = mx + v[n - sz + 1];
		for(int i = om; i + sz - 1 < n; ++i){
			tmp = max(tmp, mx + v[i] - v[i + sz]);
		}
	}
	ans = min(ans, ans - tmp);

	//----------------------------------------------------------------------
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}