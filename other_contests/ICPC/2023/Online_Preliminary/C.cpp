#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll ans = 0;
	for(int i = 0; i + 1 < n; ++i){
		ll mn1 = a[i], mn2 = a[i + 1];
		if(mn1 > mn2){
			swap(mn1, mn2);
		}
		for(int j = i + 1; j < n; ++j){
			if(mn1 > a[j]){
				mn2 = mn1;
				mn1 = a[j];
			}else if(mn2 > a[j]){
				mn2 = a[j];
			}
		}
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

	return 0;
}
