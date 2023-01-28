#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> aa(n);
	for(int i = 0; i < n; ++i)
		cin >> aa[i];
	map<int, int> odd, even;
	for(int i = 0; i < n; i += 2){
		++odd[aa[i]];
	}
	for(int i = 1; i < n; i += 2){
		++even[aa[i]];
	}
	set<pair<int, int> > odd_s, even_s;
	for(int i = 1; i < n; i += 2){
		odd_s.insert({odd[aa[i]], aa[i]});
	}
	for(int i = 0; i < n; i += 2){
		even_s.insert({even[aa[i]], aa[i]});
	}
	int a, b, x, y;
	tie(x, a) = *(--odd.end());
	odd.erase(--odd.end());
	tie(y, b) = *(--even.end());
	even.erase(--even.end());
	if(a == b){
		if(x > y){
			tie(y, b) = *(--odd.end());
		}else{
			tie(x, a) = *(--even.end());
		}
	}
	cout << (n - x - y) << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}