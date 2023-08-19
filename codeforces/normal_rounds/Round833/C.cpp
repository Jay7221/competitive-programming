#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), pre(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pre[i] = a[i];
	}
	for(int i = 1; i < n; ++i)
		pre[i] += pre[i - 1];
	map<ll, ll> freq;
	multiset<ll> s;
	ll ans = 0;
	for(int i = n - 1; i > -1; --i){
		if(freq[pre[i]] > 0){
			s.erase(s.find(freq[pre[i]]));
		}
		++freq[pre[i]];
		s.insert(freq[pre[i]]);
		if(a[i] == 0){
			ll mx = 1;
			if(s.size()){
				mx = *(--s.end());
			}
			ans += mx;
			freq.clear();
			s.clear();
		}
	}
	ans += freq[0];
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}