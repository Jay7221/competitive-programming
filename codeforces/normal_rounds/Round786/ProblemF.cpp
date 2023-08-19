#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> p = a;
	sort(p.begin(), p.end());
	int ans = (p[0] + 1) / 2 + (p[1] + 1) / 2;
	// cerr << ans << '\n';
	for(int i = 1; i < n - 1; i++){
		ans = min(ans, max(a[i - 1], a[i + 1]));
	}
	// cerr << ans << '\n';
	for(int i = 0; i < n - 1; i++){
		int x = max(a[i], a[i + 1]);
		int y = min(a[i], a[i + 1]);
			ans = min(ans, x - y + max(0, ( (2 *(2 * y - x) + 2) / 3)));
		ans = min(ans, (x + 1) / 2 + max(0, (y + 1 - (x + 1) / 2) / 2));
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}