#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i < n + 1; ++i)
		cin >> b[i];
	vector<vector<pair<int, int> > > rng(n + 1);
	for(int i = 1; i < n + 1; ++i){
		if(b[i] == 0){
			rng[i + 1].push_back({n, i});
		}else{
			rng[i / (b[i] + 1) + 1].push_back({i / b[i], i});
		}
	}
	set<pair<int, int> > s;
	for(int i = 1; i < n + 1; ++i){
		for(auto p : rng[i]){
			s.insert(p);
		}
		int r, ind;
		tie(r, ind) = *s.begin();
		s.erase(s.begin());
		a[ind] = i ;
	}
	for(int i = 1; i < n + 1; ++i){
		cout << a[i] << ' ' ;
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