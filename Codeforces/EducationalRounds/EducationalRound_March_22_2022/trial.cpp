#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
void solve(){
	ll n, C;
	cin >> n >> C;
	vi costs(n);
	vector<double> data(n);
	ll c, d, h;
	for(int i = 0; i < n; i++){
		cin >> c >> d >> h;
		data[i] = (double)c/ (h * d);
	}
	sort(data.begin(), data.end());
	ll m;
	cin >> m;
	for(ll i = 0; i < m; i++){
		ll D, H;
		cin >> D >> H;
		ll l = D * H;
		cout << (int)(data[0] * l) + 1 << ' ';

	}
}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}