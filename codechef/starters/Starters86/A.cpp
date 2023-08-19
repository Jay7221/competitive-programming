#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = INF;
	auto get = [&](int i){
		int ans = 0;
		if(i > 0){
			ans = max(ans, abs(a[i] - a[i - 1]));
		}
		if(i < n - 1){
			ans = max(ans, abs(a[i + 1] - a[i]));
		}
		return ans;
	};
	for(int i = 0; i < n; ++i){
		ans = min(ans, get(i));
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

	return 0;
}
