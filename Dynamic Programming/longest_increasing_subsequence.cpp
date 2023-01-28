#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i= 0; i < n; ++i)
		cin >> a[i];
	vector<int> cur;
	vector<int> dp(n);
	for(int i = 0; i < n; ++i){
		auto k = lower_bound(cur.begin(), cur.end(), a[i]);
		if(k == cur.end()){
			cur.push_back(a[i]);
		}else{
			*k = a[i];
		}
		dp[i] = cur.size();
	}
	cout << dp[n - 1] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}