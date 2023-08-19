#include<iostream>
using namespace std;
#define ll long long
void solve(){
	ll L, N;
	cin >> L >> N;
	ll cur = 0, ans = 0;
	for(int i = 1; i <= N; ++i){
		ll D;
		char ch;
		cin >> D >> ch;
		if(ch == 'C')
			cur += D;
		else
			cur -= D;
		ans += abs(cur / L);
		cur %= L;
	}
	cout << ans << '\n';
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}