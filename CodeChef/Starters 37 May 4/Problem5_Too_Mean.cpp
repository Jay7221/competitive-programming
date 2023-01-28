#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define ld long double
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	double sum = accumulate(a.begin(), a.end(), (double)0), sum2 = 0;
	double ans = sum / n;
	for(int i = 0; i < n; i++){
		sum2 += a[i];
		ans = max(ans, ((sum - sum2) + sum2 / (double(i + 1)) ) / (double(n - i)) );
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