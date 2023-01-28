#include<bits/stdc++.h>
using namespace std;
#define fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi std::vector<ll>
#define vb std::vector<bool>
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ';}cerr << '\n';
void solve(){
	ll n, k;
	cin >> n >> k;
	vi a(n + 1);
	a[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vi s(n + 1);
	s[0] = a[0];
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	int ans = n;
	for(int i = 1; i <= n; i++){
		if(k < s[i]){
			ans = i;
			break ;
		}
	}
	if(ans <= n){
		int unaff = a[ans];
		if(s[ans] - unaff / 2 > k){
			ans--;
		}
	}
	if(ans > n){
		ans--;
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}