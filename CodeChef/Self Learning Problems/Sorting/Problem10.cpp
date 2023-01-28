#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vp vector<pair<int, int>>
void solve(){
	int n, k;
	cin >> n >> k ;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 1e9;
	for(int i = 0; i < n - k + 1; i++){
		ans = min(ans, a[i + k - 1] - a[i]);
	}
	cout << ans << '\n';
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while(T--){
		solve();
	}
	return 0;
}
