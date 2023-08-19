#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		sum += a;
	}
	cout << max(0, sum - m) << '\n';
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