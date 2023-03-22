#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		if(ch == '0'){
			++cnt0;
		}else{
			++cnt1;
		}
	}
	int diff = cnt1 - cnt0;
	if((diff % 2 == 1) || (cnt1 == 0)){
		cout << -1 << '\n';
		return ;
	}
	int ans = 0;
	while(diff > 0){
		++ans;
		diff -= 4;
	}
	while(diff < 0){
		diff += 2;
		++ans;
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
