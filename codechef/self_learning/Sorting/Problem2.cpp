#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1e6
void solve(){
	ll N, D;
	cin >> N >> D;
	ll L[N];
	for(ll i = 0; i < N; i++){
		cin >> L[i];
	}
	sort(L, L + N);
	for(ll i = N - 1; i > 0; i--){
		L[i] = L[i] - L[i - 1];
	}
	ll i = 1;
	ll ans = 0;
	while(i < N){
		if(L[i] <= D){
			ans++;
			i += 2;
		}
		else{
			i++;
		}
	}
	cout << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	while(T--){
		solve();
	}
}