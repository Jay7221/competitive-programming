#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int a, b;
	cin >> a >> b;
	int ans;
	a += b;
	if(a < 3){
		ans = 1;
	}else if(a <= 10){
		ans = 2;
	}else if(a <= 60){
		ans = 3;
	}else{
		ans = 4;
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

	return 0;
}
