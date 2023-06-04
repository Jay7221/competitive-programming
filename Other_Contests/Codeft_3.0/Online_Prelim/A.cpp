#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a, b, c, d;
    ll ans = 0;
    cin >> a >> b >> c >> d;
    ans = max({ans, ans + a, ans + b, ans + c, ans + d, ans + a + c, ans + b + d});
    cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}

	return 0;
}
