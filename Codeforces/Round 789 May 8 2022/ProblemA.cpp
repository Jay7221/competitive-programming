#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> freq;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		freq[a[i]]++;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	if(a[0] == 0){
		ans = n - freq[0];
	}else{
		int mx = 1;
		for(auto c : freq)
			mx = max(mx, c.second);
		if(mx > 1)
			ans = n;
		else
			ans = n + 1;
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