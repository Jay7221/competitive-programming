#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool solve(){
	int n;
	cin >> n;
	ll k;
	cin >> k;
	vector<string> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	for(int i = 0; i < n; ++i){
		if(a[i].size() != b[i].size()){
			return false;
		}
	}
	map<char, int> freq;
	for(int i = 0; i < n; ++i){
		for(char ch : a[i]){
			++freq[ch];
		}
		for(char ch : b[i]){
			--freq[ch];
		}
	}
	for(int i = 0; i < 26; ++i){
		k -= abs(freq[i + 'a']);
	}
	if(k < 0){
		return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		if(solve()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}
