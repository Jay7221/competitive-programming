#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	string t;
	auto check = [&](string pat){
		int k = pat.size();
		for(int i = 0; i + k <= m; ++i){
			if(b.substr(i, k) == pat){
				return true;
			}
		}
		return false;
	};
	if(a[0] == b[0]){
		t.push_back(a[0]);
		t.push_back('*');
	}else if(a[n - 1] == b[m - 1]){
		t.push_back('*');
		t.push_back(a[n - 1]);
	}else{
		for(int i = 0; i + 1 < n; ++i){
			string tmp = a.substr(i, 2);
			if(check(tmp)){
				t = "*" + tmp + "*";
				break;
			}
		}
	}
	if(t.size()){
		cout << "YES\n";
		cout << t << '\n';
	}else{
		cout << "NO\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
