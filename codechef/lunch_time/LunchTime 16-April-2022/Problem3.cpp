#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){ cerr << c.first << ' ' << c.second << '\n';} cerr << '\n';
vector<pair<int, int> > factorize(ll x){
	// cerr << x << " : ";
	vector<pair<int, int> > ans;
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i)
			continue ;
		int k = 0;
		while(x % i == 0){
			k++;
			x = x / i;
		}
		ans.push_back({i, k});
		// cerr << "{" << i << " , " << k << "} ";
	}
	if(x != 1)
		ans.push_back({x, 1});
	cerr << '\n';
	return ans;
}
void solve(){
	ll x, c;
	cin >> x >> c;
	vector<pair<int, int> > fact = factorize(x);
	ll ans = 1;
	// debug(fact)
	for(auto par : fact){
		int p, k;
		tie(p, k) = par;
		k %= c;
		if(k > c / 2)
			k = c - k;
		ans *= pow(p, k);
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
}