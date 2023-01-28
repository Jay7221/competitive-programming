#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, x, k;
	cin >> n >> x >> k;
	assert(n >= x);
	vector<int> price(n);
	for(int i = 0; i < n; i++){
		cin >> price[i];
		assert(price[i] > 0);
	}
	x--;
	int ans = price[x];
	// debug(price)
	for(int i = 0; i < n; i++){
		ans = min(ans, price[i] + k * abs(x - i));
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