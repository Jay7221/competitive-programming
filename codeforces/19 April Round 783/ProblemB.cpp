#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	m -= n;
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.rbegin(), a.rend());
	m -= 2 * a[0];
	if(m < 0){
		cout << "NO\n";
		return ;
	}
	for(ll i = 1; i < n - 1; i++){
		m -= a[i];
		if(m < 0){
			cout << "NO\n";
			return ;
		}
	}
	if(m < 0){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
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