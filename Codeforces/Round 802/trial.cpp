#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0;  i < n; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 1; i < n; ++i){
		b[i] ^= b[i - 1];
	}
	set<int> s;
	multiset<int> m;
	vector<int> dp(n);
	for(int i = 0; i < n - 1; ++i){
		s.insert(b[i]);
		dp[i] = s.size();
		m.insert(b[i]);
	}
	int j = n - 1;
	int ans = s.size();
	s.insert(b[n - 1]);
	m.insert(b[n - 1]);
	dp[n - 1] = s.size();
	while(j > 0 && dp[j] == dp[n - 1]){
		m.erase(m.find((b[j])));
		if(m.find(b[j]) == m.end()){
			s.erase(b[j]);
			++ans;
			break ;
		}
		--j;
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