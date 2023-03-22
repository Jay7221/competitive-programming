#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
// map<pi, int> dp;
// map<pi, bool> vis;
vector<int> a;
// int gurdy(int l, int r){
// 	if(l > r){
// 		return 0;
// 	}
// 	if(vis[{l, r}]){
// 		return dp[{l, r}];
// 	}
// 	int prev = max(a[l - 1], a[r + 1]);
// 	vector<bool> vis_g(3);
// 	if(a[l] > prev){
// 		if(max(a[l + 1], a[r]) > a[l]){
// 			vis_g[gurdy(l + 1, r)] = true;
// 		}else{
// 			vis_g[0] = true;
// 		}
// 	}
// 	if(a[r] > prev){
// 		if(max(a[l], a[r - 1]) > a[r]){
// 			vis_g[gurdy(l, r - 1)] = true;
// 		}else{
// 			vis_g[0] = true;
// 		}
// 	}
// 	int ans = 0;
// 	while(vis_g[ans]){
// 		++ans;
// 	}
// 	vis[{l, r}] = true;
// 	return dp[{l, r}] = ans;
// }
void solve(){
	int n;
	cin >> n;
	a.assign(n + 2, -1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int l = 1, r = n;
	while(a[l] < a[l + 1]){
		++l;
	}
	while(a[r] < a[r - 1]){
		--r;
	}
	r = n + 1 - r;
	if((l % 2) || (r % 2)){
		cout << "Alice\n";
	}else{
		cout << "Bob\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
