#include<bits/stdc++.h>
using namespace std;
void solve(){
	string str;
	cin >> str;
	int n;
	int m = str.size();
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	vector<int> ind(m, -1);
	auto check = [&](int i, string st){
		if(m - i < st.size())
			return 0;
		for(int j = i; j < i + st.size(); ++j){
			if(str[j] != st[j - i]){
				return 0;
			}
		}
		return 1;
	};
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(check(i, s[j])){
				if(ind[i] == -1){
					ind[i] = j;
				}else if(s[ind[i]].size() < s[j].size()){
					ind[i] = j;
				}
			}
		}
	}
	set<int> st;
	for(int i = 0; i < n; ++i){\
		if(ind[i] != -1){
			st.insert(-i);
		}
	}
	vector<pair<int, int> > ans;
	int i = m - 1;
	while(i > -1){
		bool flag = 1;
		int index = -1;
		for(int j = 0; j < i + 1; ++j){
			if(ind[j] == -1)
				continue ;
			if(s[ind[j]].size() + j > i){
				ans.push_back({j, ind[j]});
				i = j - 1;
				flag = 0;
				break;
			}
		}
		if(flag){
			cout << -1 << '\n';
			return ;
		}
	}
	cout << ans.size() << '\n';
	for(auto c : ans){
		cout << c.second + 1 << ' ' << c.first + 1 << '\n';
	}
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