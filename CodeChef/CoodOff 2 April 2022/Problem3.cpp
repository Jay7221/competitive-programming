#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a ){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<ll> left(n + 2, 0), right(n + 2, 0), total(n + 2, 0);
	for(int i = 1; i < n + 1; i++)
		cin >> left[i];
	for(int i = 1; i < n + 1; i++)
		cin >> right[i];
	left[1] = 0;
	right[n] = 0;
	for(int i = 0; i < n + 2; i++)
		total[i] = left[i] + right[i];


	vector<ll> left_one(n + 2, 0), right_one(n + 2, 0);

	for(int i = 1; i <= n; i++)
		left_one[i] = min(right[i - 1], left[i]);
	for(int i = 1; i <= n; i++)
		right_one[i] = min(right[i], left[i + 1]);
	

	vector<ll> sum_left(n + 2, 0), sum_right(n + 2, 0);
	for(int i = 1; i < n + 1; i++){
		sum_left[i] = left_one[i] + sum_left[i - 1];
	}
	for(int i = n; i > 0; i--){
		sum_right[i] = right_one[i] + sum_right[i + 1];
	}
	// debug(sum_left)
	// debug(sum_right)
	ll ans = total[1] + sum_left[0] + sum_right[2];
	for(int i = 1; i < n + 1; i++){
		ans = min(ans, total[i] + sum_left[i - 1] + sum_right[i + 1]);
	}
	cout << ans << '\n';


}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}