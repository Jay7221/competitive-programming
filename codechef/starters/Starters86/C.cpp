#include<bits/stdc++.h>
using namespace std;
#define ll long long
int help(){
	int n;
	cin >> n;
	int x;
	cin >> x;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	auto check = [&](int x){
		set<int> s;
		for(int i = 0; i < n; ++i){
			s.insert(x | a[i]);
		}
		return (s.size() > 1);
	};
	if(check(x)){
		return x;
	}
	for(int k = 0; k < 30; ++k){
		x ^= (1 << k);
		if(check(x)){
			return x;
		}
		x |= (1 << k);
	}
	return 0;
}
void solve(){
	cout << help() << '\n';
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
