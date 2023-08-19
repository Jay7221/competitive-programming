#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> pos(n);
	for(int i = 0; i < n; i++){
		int u;
		cin >> u;
		pos[u] = i;
	}
	int l = n, r = -1;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(pos[i] < l || r < pos[i]){
			l = min(l, pos[i]);
			r = max(r, pos[i]);
		}
		else{
			ans += r - l - i ;
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
}