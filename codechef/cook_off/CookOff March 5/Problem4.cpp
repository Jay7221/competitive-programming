#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll X, ll t, ll N){
	if(X % t != 0){
		return 0;
	}
	ll k = X / t;
	if(k < N - t + 2){
		return 1;
	}
	return 0;
}
void solve(){
	ll N, X;
	cin >> N >> X;
	for(ll i = 1; i <= N; i++){
		if(check(X, i, N)){
			cout << "YES" << "\n";
			return ;
		}
	}
	cout << "NO" << "\n";
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int N;
	while(T--){
		solve();
	}
	return 0;
}
