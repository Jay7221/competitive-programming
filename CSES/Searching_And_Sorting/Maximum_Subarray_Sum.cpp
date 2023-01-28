#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	int x;
	cin >> x;
	a[0] = x;
	// debug(a)
	long long ans = x;
	for(int i = 1; i < n; i++){
		ll x;
		cin >> x;
		a[i] = max(x, x + a[i - 1]);
		ans = max(a[i], ans);
	}
	cout << ans << '\n';
}