#include<bits/stdc++.h>
using namespace std;
void solve(){
	auto debug = [&](vector<int> &v){
		for(auto c  : v)
			cerr << c << ' ';
		cerr << '\n';
	};
	auto debugch = [&](vector<char> &v){
		for(auto c  : v)
			cerr << c << ' ';
		cerr << '\n';
	};
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> freq(26);
	for(auto ch : s){
		++freq[ch - 'a'];
	}
	vector<int> pre(26, k);
	for(int i = 1; i < 26; ++i){
		pre[i] = min(pre[i - 1], freq[i - 1]);
	}
	for(int i = 2; i < min(n / k + 1, 26); ++i){
		pre[i - 1] -= pre[i];
	}
	vector<char> buf;
	for(int i = 0; i < min(n / k + 1, 26); ++i){
		for(int j = 0; j < pre[i]; ++j)
			buf.push_back('a' + i);
	}

	sort(buf.rbegin(), buf.rend());

	string ans;
	for(int i = 0; i < k; ++i){
		ans.push_back(buf[i]);
	}
	cout << ans << '\n';
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