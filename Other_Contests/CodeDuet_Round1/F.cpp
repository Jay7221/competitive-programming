#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int sum = accumulate(a.begin(), a.end(), 0);
	int g = a[0];
	for(int i = 0; i < n; i++){
		g = __gcd(a[i], g);
	}
	int an = (1 << 30) - 1;
	int orr = 0;
	int xorr = 0;
	for(int i = 0; i < n; ++i){
		an &= a[i];
		orr |= a[i];
		xorr ^= a[i];
	}
	cout << sum << ' ' << g << ' ' << xorr << ' ' << an << '\n';
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
