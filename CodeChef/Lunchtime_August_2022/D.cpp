#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, k;
	cin >> n >> k;
	set<ll> s;
	for(int i = 0; i < n + 1; ++i)
		s.insert(i);
	if(k > (n * (n + 1)) / 2){
		cout << -1 << '\n';
		return ;
	}
	vector<int> p(n + 1);
	int cur = n;
	for(int i = 0; i < n + 1; ++i){
		if(k >= cur){
			p[i] = *s.rbegin();
			s.erase(--s.end());
			k -= cur;
		}else{
			p[i] = i;
			s.erase(i);
		}
		--cur;
	}
	if(k){
		cerr << k << '\n';
		cout << -1 << '\n';
		return ;
	}
	for(auto elem : p)
		cout << elem << ' ';
	cout << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}