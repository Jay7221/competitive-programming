#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi (double)(3.141592653589793238462)
#define mod (int)(1e9 + 7)
void solve(){
	ll r, a, b;
	cin >> r >> a >> b;
	double ans = 0;
	while(r > 0){
		ans += pi * r * r;
		r *= a;
		ans += pi * r * r;
		r /= b;
	}
	cout << fixed << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}