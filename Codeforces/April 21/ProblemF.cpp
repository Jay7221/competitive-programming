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
	vector<ll> pre(n, 0), suf(n, 0);
	pre[0] = a[0], suf[n - 1] = a[n - 1];
	for(int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + a[i];
	for(int i = n - 2; i > -1; i--)
		suf[i] = suf[i + 1] + a[i];
	int i = 0, j = n - 1;
	int ans = 0;
	while(i < j){
		if(pre[i] == suf[j])
			ans = n - j + i + 1;
		if(pre[i] < suf[j]){
			i++;
			continue ;
		}
		if(suf[j] < pre[i]){
			j--;
			continue ;
		}
		if(a[i + 1] < a[j - 1])
			i++;
		else
			j--;
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