#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define T (int)1e3
#define N (int)1e5
#define A (int)1e9
void solve(){
	ll n = rand() % N;
	ll m = rand() % N;
	++n;
	cout << n << ' ' << m  << '\n';
	set<pair<ll, ll> > s;
	m %= ((n * (n - 1))) / 2;
	for(int i = 0; i < m; ++i){
		ll u = 0, v = 1;
		while(s.find({u, v}) != s.end()){
			u = rand() % n, v = rand() % n;
		}
		s.insert({u, v});
	}
	for(auto c : s)
		cout << c.first << ' ' << c.second << '\n';
	for(int i = 0; i < n; ++i){
		cout << rand() % A << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(0));
	int t = rand() % T;
	++t;
	cout << t << '\n';
	while(t--){
		solve();
	}
}