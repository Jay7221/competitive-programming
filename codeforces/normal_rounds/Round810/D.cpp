#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll> > v, a;
	for(int i = 0; i < n; ++i){
		int x, p;
		cin >> x >> p;
		v.push_back({x, p});
	}
	a = v;
	sort(a.begin(), a.end());
	for(auto c : a){
		int x, y;
		tie(x, y) = c;
		cerr << "{" << x << ", " << y << "}, " ;
	}
	cerr << '\n';
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