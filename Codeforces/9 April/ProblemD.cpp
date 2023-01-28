#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n ;i++)
		cin >> b[i];
	for(int i = 0;i < n; i++)
		a[i] = min(0, a[i] - b[i]);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += abs(a[i]);
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	t = 1;
	while(t--){
	solve();
	}
}