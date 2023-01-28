#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n;
	vector<int> a(n);
	map<int, ll> freq;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
	for(int i = 0; i < n; i++)
		freq[a[i] & x]++;
	ll ans = 0;
	for(auto c : freq)
		ans += c.second * c.second;
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