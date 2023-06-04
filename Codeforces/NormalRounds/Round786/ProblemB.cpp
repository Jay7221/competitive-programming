#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	char a, b;
	cin >> a >> b;
	int x = a - 'a', y = b - 'a';
	// cerr << x << ' ' << y << '\n';
	int ans = 25 * x;
	ans += y + (y < x);
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
}