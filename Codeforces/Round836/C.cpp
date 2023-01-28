#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
vector<int> factorize(int n){
	vector<int> primes;
	for(int i = 2; i * i <= n; ++i){
		while(n % i == 0){
			primes.push_back(i);
			n /= i;
		}
	}
	if(n > 1)
		primes.push_back(n);
	return primes;
}
void solve(){
	int n, x;
	cin >> n >> x;
	if(n % x){
		cout << -1 << '\n';
		return ;
	}
	vector<int> p(n + 1);
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	p[n] = 1;
	p[1] = x;
	int cur = x;
	for(auto prime : factorize(n / x)){
		p[cur] = cur * prime;
		cur = cur * prime;
	}
	for(int i = 1; i <= n; ++i)
		cout << p[i] << ' ';
	cout << '\n';
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