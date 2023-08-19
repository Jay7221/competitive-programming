#include<bits/stdc++.h>
using namespace std;
void solve(int t){
	int n;
	cin >> n;
	auto to_string = [&](int num){
		string ans = "..........";
		for(int i = 0; i < 10; ++i){
			if((num >> i) & 1){
				ans[i] = '-';
			}
		}
		return ans;
	};
	string c;
	cin >> c;
	int k = c.size();
	k = min(k, 10);
	vector<string> ans;
	for(int i = 0; (i < (1 << 10)) && (ans.size() < n - 1); ++i){
		string tmp = to_string(i);
		if(tmp.substr(0, k) != c.substr(0, k)){
			ans.push_back(tmp);
		}	
	}
	cout << "Case #" << t << ": \n" ;
	for(auto elem : ans)
		cout << elem << '\n';
}
int main(){
	int T;
	cin >> T;
	for(int t= 1; t <= T; ++t){
		solve(t);
	}
}