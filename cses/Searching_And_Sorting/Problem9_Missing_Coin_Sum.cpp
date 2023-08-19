#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a) {cerr << c << ' ';} cerr << '\n';
#define ll long long
int main(){
	int n;
	cin >> n;
	vector<ll> x(n + 1, 0);
	for(int i = 1; i < n + 1; i++)
		cin >> x[i];
	vector<ll> s(n + 1, 0);
	sort(x.begin(), x.end());
	ll ans = 1e16 + 7;
	for(int i = 1; i < n + 1; i++){
		s[i] = s[i - 1] + x[i];
		if(x[i] > s[i - 1] + 1){
			// cerr << x[i] << ' ' << s[i - 1] << ' ' << i << '\n';
			ans = min(ans, s[i - 1] + 1);
		}
	}
	// debug(s)
	ans = min(ans, s[n] + 1);
	cout << ans << '\n';
}