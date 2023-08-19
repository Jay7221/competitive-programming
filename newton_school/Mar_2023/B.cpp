#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int cur = v[0].first;
	for(int i = 0; i < n; ++i){
		int a, b;
		tie(a, b) = v[i];
		cur = max(cur, a);
		ans += max(0, b - cur);
		cur = max(cur, b);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
