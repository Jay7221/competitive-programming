#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n >> x;
	int greatest_misplaced = 0;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int mx = a[0];
	int max_used = 0;
	for(int i = 0; i < n; ++i){
		mx = max(mx, a[i]);
		if(a[i] < mx){
			max_used = max(max_used, a[i] + mx);
		}
	}
	if(max_used > x){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}
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