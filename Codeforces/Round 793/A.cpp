#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a;
	for(int i = 0; i < n; ++i){
		int sz = 1;
		while(i + 1 < n && s[i + 1] == s[i]){
			++i, ++sz;
		}
		a.push_back(sz);
	}
	n = a.size();
	cout << a[(n + 1)/ 2 - 1] << '\n';
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
}