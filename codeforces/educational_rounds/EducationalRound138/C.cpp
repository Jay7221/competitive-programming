#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	auto check = [&](int k){
		bool flag = true;
		multiset<int> m;
		for(int i = 0; i < n; ++i)
			m.insert(a[i]);
		for(int i = k; i > 0; --i){
			if(m.size() == 0){
				flag = false;
				break ;
			}
			if(*m.begin() > i){
				flag = false;
				break ;
			}
			m.erase(--m.upper_bound(i));
			if(m.size() > 0){
				m.erase(m.begin());
			}
		}
		return flag;
	};
	int l = 0, r = n;
	while(l < r){
		int m = (l + r + 1) / 2;
		if(check(m)){
			l = m;
		}else{
			r = m - 1; 
		}
	}
	cout << l << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}