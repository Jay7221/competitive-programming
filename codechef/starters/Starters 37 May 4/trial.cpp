#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define ld double
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll sum = accumulate(a.begin(), a.end(), 0ll), sum2 = 0;
	double ans = (ld)sum / (ld)n;
	for(int i = 0; i < n; i++){
		sum2 += a[i];
		ans = max(ans, ((ld)(sum - sum2) + (ld)sum2 / (double(i + 1)) ) / (double(n - i)) );
	}
	cout << fixed << setprecision(10);
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