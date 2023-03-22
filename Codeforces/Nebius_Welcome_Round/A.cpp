#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int a, b;
	cin >> a >> b;
	a = abs(a);
	b = abs(b);
	if(a < b){
		swap(a, b);
	}
	int d = a - b;
	int ans = 2 * b;
	if(d > 0){
		// add the extra
		ans += d + (d - 1);
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
