#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<pair<int, int> > ans;
	bool flag = 0;
	for(int k = 0; k < 30; ++k){
		ans.clear();
		int l = 0;
		ll cur = a[0];
		for(int i = 1; i < n; ++i){
			if((a[i] & (1ll << k)) && (cur & (1ll << k))){
				ans.push_back({l, i - 1});
				cur = a[i];
				l = i;
			}else{
				cur += a[i];
			}
		}
		if(cur & (1ll << k)){
			ans.push_back({l, n - 1});
			l = n;
		}
		if(l == n && ans.size() > 1){
			flag = 1;
			break ;
		}
		ans.clear();
		int r = n - 1;
		cur = a[n - 1];
		for(int i = n - 2; i > -1; --i){
			if((cur & (1ll << k)) && (a[i] & (1ll << k))){
				ans.push_back({i + 1, r});
				r = i;
				cur = a[i];
			}else{
				cur += a[i];
			}
		}
		if(cur & (1ll << k)){
			ans.push_back({0, r});
			r = -1;
		}
		if(r == -1 && ans.size() > 1){
			flag = 1;
			break ;
		}
	}
	if(flag == 0){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	cout << ans.size() << '\n';
	for(auto p : ans){
		int l, r ;
		tie(l, r) = p;
		cout << l + 1 << ' ' << r + 1 << '\n';
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