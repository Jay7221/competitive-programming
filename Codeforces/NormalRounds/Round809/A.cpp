#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		--a[i];
	}
	vector<pair<int, int> > v(n);
	for(int i = 0; i < n; ++i){
		v[i].first = min(a[i], m - 1 - a[i]);
		v[i].second = max(a[i], m - 1 - a[i]);
	}
	vector<char> s(m, 'B');
	sort(v.begin(), v.end());
	for(auto c : v){
		int x, y;
		tie(x, y) = c;
		if(s[x] == 'A'){
			s[y] = 'A';
		}else{
			s[x] = 'A';
		}
	}
	for(auto c : s){
		cout << c ;
	}
	cout << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}