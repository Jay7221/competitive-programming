#include<bits/stdc++.h>
using namespace std;
void solve(int t){
	int n, k;
	cin >> n >> k;
	vector<int> s(n);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	bool flag = 1;
	if((2 * k) < n){
		flag = 0;
	}
	vector<int> freq(101);
	for(auto elem : s)
		++freq[elem];
	for(int i = 0; i <= 100; ++i){
		if(freq[i] > 2){
			flag = 0;
		}
	}
	string ans;
	if(flag)
		ans = "YES";
	else
		ans = "NO";
	cout << "Case #" << t << ": " << ans << "\n";
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve(t);
	}
}