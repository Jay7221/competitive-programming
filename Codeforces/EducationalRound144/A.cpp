#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string pat = "FBFFBFFB";
	int m = pat.size();
	auto check = [&](int k){
		for(int i = 0; i < n; ++i){
			if(s[i] != pat[k]){
				return false;
			}
			k = (k + 1) % m;
		}
		return true;
	};
	bool flag = false;
	for(int i = 0; i < m; ++i){
		if(check(i)){
			flag = true;
		}
	}
	if(flag){
		cout << "YES\n";
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
