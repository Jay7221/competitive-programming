#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> pre(n, 0), suf(n, 0);
	for(int i = 1; i < n; i++){
		pre[i] = pre[i - 1];
		if(a[i] % 2 == a[0] % 2)
			pre[i] += 1;
	}
	for(int i = n - 2; i > -1; i--){
		suf[i] = suf[i + 1];
		if(a[i] % 2 == a[n - 1] % 2)
			suf[i] += 1;
	}
	if(a[n - 1] % 2 == a[0] % 2){
		cout << pre[n - 1] << '\n';
		return ;
	}
	int ans = n;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == a[0] % 2 || a[i] % 2 == a[n - 1] % 1){
		    ans  = min(ans, pre[i] + suf[i] + 1);
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