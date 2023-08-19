#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<ll> mx(n), mn(n);
	for(auto m : a){
		mx[0] += n - m + 1;
		mn[0] += 1;
		if(m < n){
			mx[m] -= 1;
			mn[m] -= 1;
		}
	}
	for(int i = 1; i < n; ++i){
		mx[i] += mx[i - 1];
		mn[i] += mn[i - 1];
	}
	for(auto m : a){
		if(m < n){
			mx[m] -= n - m;
		}
	}
	for(int i = 0; i < n; ++i){
		cout << mn[i] << ' ' << mx[i] << '\n';
	}
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