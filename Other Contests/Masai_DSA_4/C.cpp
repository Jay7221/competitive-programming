#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &v){
	for(int elem : v){
		cerr << elem<< ' ';
	}
	cerr << '\n';
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	multiset<int> m;
	for(int i = 0; i < n; ++i){
		m.insert(a[i]);
	}
	sort(a.begin(), a.end());
	auto get = [&](int a){
		int ans = -1;
		if(m.find(a) != m.end()){
			m.erase(m.find(a));
			if(m.lower_bound(a) != m.end()){
				ans = (*(m.lower_bound(a)) - a);
			}
			m.insert(a);
		}
		return ans;
	};
	set<pair<int, int>> st;
	for(int i = 0; i < n; ++i){
		if(get(a[i]) != -1){
			st.insert({get(a[i]), i});
		}
	}
	vector<tuple<int, int>> ans;

	while(st.size()){
		int i, tmp;
		tie(tmp, i) = *st.begin();
		st.erase(st.begin());
		if(m.lower_bound(a[i]) != m.end()){
			ans.push_back(a[i], m.lower_bound(a[i]));
			m.erase(m.lower_bound(a[i]));
		}
	}

	for(auto [x, u, v] : ans){
		cout << u << ' ' << v << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}