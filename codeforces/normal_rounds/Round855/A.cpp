#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	map<char, int> mp;
	mp['M'] = mp['m'] = 1;
	mp['E'] = mp['e'] = 2;
	mp['O'] = mp['o'] = 3;
	mp['W'] = mp['w'] = 4;
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		v[i] = mp[ch];
	}
	bool flag = true;
	for(int i = 0; i < n; ++i){
		if(v[i] == 0){
			flag = false;
			break;
		}
		if(i > 0){
			if((v[i] != v[i - 1]) && (v[i] != v[i - 1] + 1)){
				flag = false;
				break;
			}
		}
	}
	if((v[0] != 1) || (v[n - 1] != 4)){
		flag = false;
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
