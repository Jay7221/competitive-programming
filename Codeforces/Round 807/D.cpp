#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr  << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<bool> s(n), t(n), a(n - 1), b(n - 1);
	string st; 
	cin >> st;
	for(int i = 0; i < n; ++i)
		s[i] = st[i] - '0';
	cin >> st;
	for(int i = 0; i < n; ++i)
		t[i] = st[i] - '0';
	if((t[0] != s[0]) || (t[n - 1] != s[n - 1])){
		cout << -1 << '\n';
		return ;
	}
	for(int i = 0; i < n - 1; ++i){
		a[i] = s[i] ^ s[i + 1];
		b[i] = t[i] ^ t[i + 1];
	}
	if(accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)){
		cout << -1 << '\n';
		return ;
	}
	vector<int> posa, posb;
	for(int i = 0; i < n - 1; ++i){
		if(a[i]){
			posa.push_back(i);
		}
		if(b[i]){
			posb.push_back(i);
		}
	}
	ll ans = 0;
	for(int i = 0; i < posa.size(); ++i){
		ans += abs(posa[i] - posb[i]);
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}