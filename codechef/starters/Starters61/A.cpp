#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int cnt0 = 0, cnt1 = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if(a){
			if(cnt0){
				++ans;
				--cnt0;
			}else{
				++cnt1;
			}
		}else{
			if(cnt1){
				++ans;
				--cnt1;
			}else
				++cnt0;
		}
	}
	ans += cnt1 / 3;
	cout << ans << '\n';
	return;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}


