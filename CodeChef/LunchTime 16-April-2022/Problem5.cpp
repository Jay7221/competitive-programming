#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ; } cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i = 0; i < n - 1; i++)
		ans += (a[i] % a[i + 1]);
	ans += (a[n - 1] % a[0]);
	vector<bool> visited(n, 0);
	visited[n - 1] = visited[0] = 1;
	int k = n - 1;
	int swap = 0;
	for(int t = 0; t < n - 2; t++){
		ll diff = 0;
		int next_k = -1;
		for(int p = 1; p < n - 1; p++){
			if(visited[p])
				continue ;
			ll temp_diff = (a[k] % a[p] + a[p] % a[0]) - (a[k] % a[0] + a[p]);
			if(temp_diff > diff){
				diff = temp_diff;
				next_k = p;
			}
		}
		if(next_k == -1)
			break ;
		ans += diff;
		k = next_k;
		visited[k] = 1;

	}
	// for(int t = 0; t < n - 2 && swap < n - 1; t++){
	// 	ll diff = 0;
	// 	for(int p = 1; p < n - 1 && swap < n - 1; p++){
	// 		if(visited[p])
	// 			continue ;
	// 		ll temp_diff = (a[k] % a[p] + a[p] % a[0]) - (a[k] % a[0] + a[p]);
	// 		if(temp_diff > diff){
	// 			swap += 1;
	// 			k = p;
	// 			diff = temp_diff;
	// 			ans += diff;
	// 			visited[p] = 1;
	// 		}

	// 	}
	// }
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