#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		int a;
		cin >> a;
		if((a % k) != (i % k)){
			++cnt;
		}
	}
	cnt = (cnt + 1) / 2;
	if(cnt > 1){
		cnt = -1;
	}
	cout << cnt << '\n';
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
	
	return 0;
}