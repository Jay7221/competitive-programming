#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	ll req = 2 * sum;
	ll ans = 0;
	int i = 0, j = n - 1;
	while(i < j){
		if(n * (a[i] + a[j]) < req)
			i++;
		else if(n* (a[i] + a[j]) > req)
			j--;
		else{
			if(a[i] == a[j]){
				ll k = 1;
				while(i < j && a[i] == a[j]){
					i++;
					k++;
				}
				ans += k * (k - 1) / 2;
				break ;
			}
			ll p = 1, q = 1;
			while(i + 1 < j && a[i + 1] == a[i])
				i++, p++;
			while(i < j - 1 && a[j - 1] == a[j])
				j--, q++;
			ans += p * q;
			i++, j--;
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
}