#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)(1e13 + 7)
#define mx (int)(1e4 + 8)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	ll s = 0;
	vector<int> w(n);
	for(int i = 0; i < n; i++){
		s += min(a[i], b[i]);
		w[i] = abs(b[i] - a[i]);
	}
	vector<bool> pos(mx, 0);
	pos[0] = 1;
	for(auto c : w){
		for(int i = mx - 1; i > -1; --i){
			if(c + i < mx){
				pos[i + c] = (pos[i + c] | pos[i]);
			}
		}
	}
	ll k = accumulate(w.begin(), w.end(), 0ll);
	ll ans = inf;
	for(int i = 0; i < mx; i++){
		if(pos[i]){
			ans = min(ans, (ll)(pow(s + i, 2) + pow(s + k - i, 2)));
		}
	}
	for(int i = 0; i < n; i++){
		ans += (n - 2) * (pow(a[i], 2) + pow(b[i], 2));
	}
	cout << ans << "\n";
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