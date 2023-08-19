#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool can_win(ll a, int n){
	if(a < n){
		return 0;
	}
	if(a >= n && a < n * n){
		return 1;
	}
	return 1 ^ can_win(a % n * n, n);
}
void solve(){
	int n;
	cin >> n;
	ll a;
	bool who_wins = 0;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(can_win(a, n))
			who_wins = 1;
	}
	if(who_wins)
		cout << "Alice" << '\n';
	else
		cout << "Bob" << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}