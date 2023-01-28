#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	vector<bool> mark(n, 0);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	auto ok = [&](string s){
		int n = s.size();
		map<char, bool> mp;
		for(int i = 0; i < n; i++){
			if(mp[s[i]])
				return 0;
			mp[s[i]] = 1;
			char k = s[i];
			while(i < n && s[i] == k){
				i++;
			}
			i--;
		}
		return 1;
	};
	for(int i = 0; i < n; i++){
		if(mark[i])
			continue ;
		mark[i] = 1;
		string temp = s[i];
		bool  go = 1;
		while(go){
			go = 0;
			for(int j = 0; j < n; j++){
				if(mark[j])
					continue ;
				if(temp.front() == s[j].back()){
					mark[j] = 1;
					temp = s[j] + temp;
					go = 1;
					continue;
				}
				if(temp.back() == s[j].front()){
					mark[j] = 1;
					temp += s[j];
					go = 1;
					continue ;
				}
			}
		}
		s[i] = temp;
		mark[i] = 0;
	}
	string ans;
	for(int i = 0; i < n; i++){
		if(mark[i])
			continue ;
		ans += s[i];
	}
	if(ok(ans)){
		cout << ans << '\n';
	}else{
		cout << "IMPOSSIBLE\n";
	}
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}