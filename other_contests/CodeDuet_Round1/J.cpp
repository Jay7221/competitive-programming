#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a + b) % MOD);
}
ll mult(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a * b) % MOD);	
}
ll sub(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a - b) % MOD);	
}
ll power(ll a, ll p){
	ll ans = 1, rem = a;
	while(p > 0){
		if(p & 1){
			ans = mult(ans, rem);
		}
		p >>= 1;
		rem = mult(rem, rem);
	}
	return ans;
}
ll inv(ll a){
	return power(a, MOD - 2);
}
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	vector<ll> pre(n + 1);
	for(int i = 1; i <= n; ++i){
		int cur = s[i - 1] - 'a';
		cur = mult(add(cur, 100), 100);
		pre[i] = add(cur, mult(26, pre[i - 1]));
	}
	auto get_hash = [&](int i, int j){
		ll ans = sub(pre[j], mult(pre[i - 1], power(26, j - i + 1)));
		return ans;
	};
	map<int, int> freq;
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			++freq[get_hash(i, j)];
		}
	}
	cerr << get_hash(3, 4) << ' ' << get_hash(6, 7) << '\n';
	for(int k = n - 1; k >= 0; --k){
		for(int i = 1; i + k <= n; ++i){
			if(freq[get_hash(i, i + k)] > 1){
				cout << s.substr(i, k + 1) << '\n';
				return ;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
