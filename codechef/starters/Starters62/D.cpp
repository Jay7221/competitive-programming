#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l1 = 0, l2 = n;
	for(int i = 1; i < n; ++i){
		if(s[i] != s[l1]){
			l2 = i;
			break ;
		}
	}
	auto mult = [&](ll a, ll b){
		return ((a * b) % MOD);
	};
	auto add = [&](ll a, ll b){
		return ((a + b) % MOD);
	};
	ll ans = 0;
	int block = 0;
	for(int i = l2; (i < n) && (s[i] == s[l2]); ++i){
		++block;
	}
	l1 = max(0, l2 - block);
	for(int i = l1, j = l2; j < n; ++i, ++j){
		ans = mult(ans, 2);
		if(s[i] != s[j]){
			ans = add(ans, 1);
		}
	}
	cout << ans << '\n';
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