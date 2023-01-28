#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int> > v;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(abs(accumulate(a.begin(), a.end(), 0)) % 2){
		// cerr << abs(accumulate(a.begin(), a.end(), 0)) << '\n';
		cout << -1 << '\n';
		return ;
	}
	for(int i = 0; i < n; ++i){
		if(a[i] == 0){
			v.push_back({i + 1, i + 1});
		}else{
			int l = i, r = i + 1;
			while(a[r] == 0)
				++r;
			i = r;
			++l, ++r;
			cerr << l << ' ' << r << '\n';
			if((r - l) % 2){
				if(a[r] == a[l])
					v.push_back({l, r});
				else{
					v.push_back({l, l});
					v.push_back({l + 1, r});	
				}

			}else{
			if(a[r] != a[l])
					v.push_back({l, r});
				else{
					v.push_back({l, l});
					v.push_back({l + 1, r});	
				}				
			}
		}
	}
	cout << v.size() << '\n';
	for(auto [l, r] : v)
		cout << l << ' ' << r << '\n';
	return ;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}