#include<bits/stdc++.h>
using namespace std;
#define mx (int)(1e5 + 7)
vector<int> primes;
void pre(){
	vector<bool> is_prime(mx, 1);
	for(int i = 2; i < mx; ++i){
		if(!is_prime[i]){
			continue ;
		}
		for(int j = 2; j * i < mx; ++j){
			is_prime[i * j] = 0;
		}
	}
	for(int i = 2; i < mx; ++i){
		if(is_prime[i]){
			primes.push_back(i);
		}
	}
}
int gcd(int a, int b){
	while(b){
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
int fact(int x){
	int ans = 0;
	for(auto p : primes){
		while(x % p == 0){
			ans += p;
			x /= p;
		}
		if(x == 1){
			break ;
		}
	}
	return ans;
}
void solve(){
	int n;
	cin >> n;
	int q;
	cin >> q;
	while(q--){
		int u,v;
		cin >> u >> v;
		int d = gcd(u, v);
		int ans = fact(u / d) + fact(v / d);
		cout << ans << '\n';
	}
}
int main(){
	freopen("inputf.in","r",stdin);
	freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}