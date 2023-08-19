#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, r;
	cin >> n >>  r;
	int ans = 0;
	vector<int> a(n);
	vector<pair<int, int> > b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		b[i] = {a[i] - k, k};
	}
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	for(int i = 0; i < n && r > 0; i++){
		if(b[i].first  < a[0]){
			int k = (max(0, r - b[i].second)) / b[i].first;
			r -= k * b[i].first;
			ans += k;
		}else{
			break ;
		}
	}
	ans += r / a[0];
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