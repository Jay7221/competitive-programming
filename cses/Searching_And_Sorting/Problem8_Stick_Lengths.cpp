#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<ll> pre(n), suf(n);
	sort(a.begin(), a.end());
	pre[0] = 0;
	for(int i = 1; i < n; i++){
		pre[i] = pre[i - 1] + i * (a[i] - a[i - 1]);
	}
	suf[n - 1] = 0;
	for(int i = n - 2; i > -1; i--){
		suf[i] = suf[i + 1] + (n - i - 1) * (a[i + 1] - a[i]);
	}
	ll ans = pre[0] + suf[0];
	for(int i = 0; i < n; i++)
		ans = min(ans, pre[i] + suf[i]);
	cout << ans << '\n';
}