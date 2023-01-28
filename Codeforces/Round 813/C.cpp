#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ind(n + 1);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		ind[a[i]] = max(i, ind[a[i]]);
	}
	int ans = 0;
	vector<int> suf(n);
	suf[n - 1] = n - 1;
	for(int i = n - 2; i > -1; --i){
		if(a[i] < a[suf[i + 1]])
			suf[i] = i;
		else
			suf[i] = suf[i + 1];
	}
	int cur = -1;
	int mn = 1e9 + 7;
	for(int i = n - 1; i > -1; --i){
		if(a[i] > mn)
			cur = max(cur, ind[a[i]]);
		mn = min(a[i], mn);
	}
	map<int, int> freq;
	for(int i = 0; i <= cur; ++i){
		++freq[a[i]];
	}
	ans = freq.size();
	cout << ans << '\n';
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
}