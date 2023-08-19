#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1e6
void solve(){
	int n;
	cin >> n;
	map<int, int> m;
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		m[k]++;
	}
	int ans = 0;
	for(auto i : m){
		ans += i.second - 1;
	}
	cout  << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}