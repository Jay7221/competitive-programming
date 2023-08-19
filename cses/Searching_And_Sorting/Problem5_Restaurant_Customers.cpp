#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> ent(n), exit(n);
	for(int i = 0; i < n; i++){
		cin >> ent[i] >> exit[i];
	}
	sort(ent.begin(), ent.end());
	sort(exit.begin(), exit.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		int k = lower_bound(ent.begin(), ent.end(), exit[i]) - ent.begin();
		int l = lower_bound(ent.begin(), ent.end(), ent[i]) - ent.begin();
		ans = max(ans, k - l);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}