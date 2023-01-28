#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	int a1 = 0, a2 = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a1 += (a[i] + x - 1) / x;
		a2 = max(a2, a[i]);
	}
	cout << min(a1, a2) << '\n';
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