#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e7 + 7;
vector<bool> is_square(MAX, false);
void pre(){
	for(int i = 0; i * i < MAX; ++i){
		is_square[i * i] = true;
	}
}
void solve(){
	ll N;
	cin >> N;
	ll P = 1;
	for(ll i = 2; i * i <= N; ++i){
		ll sq = i * i;
		while(N % sq == 0){
			P = P * i;
			N /= sq;
		}
	}
	ll A, B;
	bool flag = false;
	for(ll i = 0; i <= sqrt(N); ++i){
		if(is_square[N - i * i]){
			A = i;
			for(ll j = A; (i * i + j * j) <= N; ++j){
				if(j * j + i * i == N){
					B = j;
					break ;
				}
			}
			flag = true;
			break ;
		}
	}
	if(flag){
		cout << (A * P) << ' ' << (B * P) << '\n';
	}else{
		cout << -1 << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}