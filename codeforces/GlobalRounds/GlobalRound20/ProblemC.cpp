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
	int fir = n, las = -1;
	for(int i = 1; i < n; i++){
		if(a[i] == a[i - 1]){
			fir = min(i - 1, fir);
			las = max(i, las);
		}
	}
	int len = max(0, las - fir + 1);
	int ans = 0;
	if(len > 3)
		ans = len - 3;
	else
		ans = max(0, len - 2);
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