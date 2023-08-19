#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr <<  c<< ' ';} cerr << '\n';
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < m; ++i){
		int a;
		cin >> a;
		--a;
		++v[a];
	}
	multiset<int> s;
	for(auto c : v){
		s.insert(c);
	}
	bool flag = 1;
	while(flag){
		int mn = *s.begin(), mx = *(--s.end());
		if(mx - mn <= 2){
			break ;
		}else{
			s.erase(s.begin());
			s.erase(--s.end());
			s.insert(mx - 1);
			s.insert(mn + 2);
		}
	}
	int ans = 0;
	for(auto c : s){
		ans = max(ans, c);
	}
	cout << ans << '\n';
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