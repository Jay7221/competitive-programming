#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
ll sum(int x, int y, vector<ll> a){
	ll ans = 0;
	for(int i = x; i < y + 1; i++)
		ans += a[i];
	return ans;
}
ll compute(int i, int j, int k, vector<ll> a){
	ll ans = 0;
	ll n = a.size();
	for(int i = 0; i < n - 3; i++){
		for(int j = i + 1; j < n - 2; j++){

		}
	}
	return ans;
}
ll find(vector<ll> a){
	ll ans = 0;
	int n = a.size();
	vector<ll> pre(n);
	pre[0] = a[0];
	for(int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + a[i];
	ll cur_s = 0, fir_ind, sec_ind, thir_ind;
	fir_ind = 0;
	for(int i = fir_ind + 1; i < n - 2; i++){
		if(pre[i] - a[i] > cur_s){
			cur_s = pre[i] - a[i];
			fir_ind  = i;
		}
	}
	pre[fir_ind] = 0;
	for(int i = fir_ind + 1; i < n; i++)
		pre[i] = pre[i - 1] + a[i];
	ans += cur_s;
	cur_s = 0;
	sec_ind = fir_ind + 1;
	for(int i = sec_ind  + 1; i < n -1; i++){
		if(pre[i] - a[i] < cur_s){
			cur_s = pre[i] - a[i];
			sec_ind = i;
		}
	}
	ans -= cur_s;
	cur_s = 0;
	pre[sec_ind] = 0;
	for(int i = sec_ind + 1; i < n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	thir_ind = sec_ind + 1;
	for(int i = thir_ind + 1; i < n; i++){
		if(pre[i] - a[i] < cur_s){
			cur_s = pre[i] - a[i];
			thir_ind = i;
		}
	}
	ans -= cur_s;
	ans += pre[n - 1] - cur_s - a[thir_ind];
	ans = 0;
	for(int i = 0; i < fir_ind; i++)
		ans += a[i];
	for(int i = fir_ind + 1; i < sec_ind; i++)
		ans -= a[i];
	for(int i = sec_ind + 1; i < thir_ind; i++)
		ans -= a[i];
	for(int i = thir_ind + 1; i < n; i++)
		ans += a[i];
	cerr << fir_ind << ' ' << sec_ind << ' ' << thir_ind << '\n';
	return ans;
}
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	ans = max(ans, find(a));
	for(int i= 0; i < n / 2; i++)
		swap(a[i], a[n - 1  - i]);
	ans = max(ans, find(a));
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