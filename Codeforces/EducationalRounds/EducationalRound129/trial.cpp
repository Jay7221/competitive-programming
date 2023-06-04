#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(n % 2){
		cout << "NO\n";
		return ;
	}
	sort(a.begin(), a.end());
	vector<int> ans(n);
	for(int i = 0, j = 0; i < n / 2; ++i, j += 2){
		ans[j] = a[i], ans[j + 1] = a[i + n / 2];
	}
	for(int i = 0; i < n; ++i){
		if(ans[i] == ans[(i + 1) % n] || ans[i] == ans[(i + n - 1) % n]){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
	for(auto c : ans)
		cout << c << ' ' ;
	cout << '\n';
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