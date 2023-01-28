#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll extra = 0;
	vector<ll> mx(n + 1), mn(n + 1), freq(n + 1);
	for(auto m : a){
		++freq[m];
		extra += n - m;
		if(m > 0){
			++mn[m - 1];
		}
	}
	for(int i = n - 1; i > 0; --i){
		mn[i - 1] += mn[i];
	}
	for(int i = 0; i < n; ++i)
		mx[i] = mn[i] + extra - freq[i] * (n - i);
	for(int i = 0; i < n; ++i){
		cout << mn[i] << ' '<< mx[i] << '\n';
	}
	cout << '\n';
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