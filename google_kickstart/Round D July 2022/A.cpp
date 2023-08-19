#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll ans = 0;
	sort(a.begin(), a.end());
	for(int i = n - 1; i > n - m; --i){
		ans += a[i];
	}
	double tmp = 0;
	if((n - m + 1) % 2 == 1){
		ans += a[(n - m) / 2];
	}else{
		tmp = ( (double)(a[(n - m) / 2] + a[(n - m) / 2 + 1]) ) / 2;
	}
	tmp += ans;
	cout << fixed;
	cout << tmp << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; ++i){
		cout << "Case #" << i << ": " ;
		solve();
	}
}