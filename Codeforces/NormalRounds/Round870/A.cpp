#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = -1;
	sort(a.begin(), a.end());
	for(int k = 0; k <= n; ++k){
		int liars = upper_bound(a.begin(), a.end(), k) - a.begin();
		liars = n - liars;
		if(liars == k){
			ans = k;
			break;
		}
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