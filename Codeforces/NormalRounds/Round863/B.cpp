#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	x = max(x, n - x + 1);
	y = max(y, n - y + 1);
	int k1 = max(x, y);
	cin >> x >> y;
	x = max(x, n - x + 1);
	y = max(y, n - y + 1);
	int k2 = max(x, y);
	cout << abs(k1 - k2) << '\n';
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
