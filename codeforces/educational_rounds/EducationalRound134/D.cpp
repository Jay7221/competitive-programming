#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
#define debug(a) for(auto c : a){cerr << c << ' ' << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int  i = 0; i < n; ++i)
		cin >> b[i];
	auto check = [&](int val){
		vector<int> x(n), y(n);
		for(int i = 0; i < n; ++i){
			x[i] = (a[i] & val);
			y[i] = (b[i] & val);
		}
		sort(x.begin(), x.end());
		sort(y.rbegin(), y.rend());
		bool ans = true;
		for(int i = 0; i < n; ++i){
			if((x[i] ^ y[i]) != val){
				ans = false;
				break ;
			}
		}
		return ans;
	};
	int ans = 0;
	for(int k = 30; k > -1; --k){
		int tmp = ans + (1 << k);
		if(check(tmp)){
			ans = tmp;
		}
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