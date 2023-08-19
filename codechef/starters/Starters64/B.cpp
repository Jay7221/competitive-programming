#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 7;
void solve(){
	int n;
	cin >> n;
	vector<int> a(2 * n), freq(MAX);
	for(int i = 0; i < 2 * n; ++i){
		cin >> a[i];
		++freq[a[i]];
	}
	bool ans = true;
	int k = n  + (n / 2) + (n % 2);
	for(int i = 0; i < 2 * n; ++i){
		if(freq[a[i]] > k)
			ans = false;
	}
	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}