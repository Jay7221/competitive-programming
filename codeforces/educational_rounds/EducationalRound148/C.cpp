#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> b;
	for(int i = 0; i < n; ++i){
		if((i + 1 < n) && (a[i] == a[i + 1])){
			continue;
		}
		b.push_back(a[i]);
	}
	a = b;
	n = a.size();
	b.clear();
	auto check = [&](int x, int y, int z){
		return (((x < y) && (y < z)) || ((x > y) && (y > z)));
	};
	for(int i = 0; i < n; ++i){
		if((b.size() > 0) && (i + 1 < n)){
			if(check(b.back(), a[i], a[i + 1])){
				continue;
			}
		}
		b.push_back(a[i]);
	}
	cout << b.size() << '\n';
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