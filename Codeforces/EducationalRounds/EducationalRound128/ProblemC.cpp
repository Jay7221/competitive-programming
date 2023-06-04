#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	vector<int> pre(n);
	for(int i = 0; i < n; ++i)
		pre[i] = (s[i] - '0');
	for(int i = 1; i < n; ++i)
		pre[i] += pre[i - 1];
	int x = pre[n - 1]; 	// number of ones in the string
	// int ans = n - x;		// considerin contribution solely from zeroes
	int ans = mod;
	if(x > 0)
		ans = min(ans, x - pre[x - 1]);
	for(int i = 0; i < n - x; ++i){
		int j = i + x;
		ans = min(ans, x - (pre[j] - pre[i]));
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
}