#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> s(n), p(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	for(int i = 1; i < n; ++i){
		cin >> p[i];
		--p[i];
	}
	for(int i = 1; i < n; ++i){
		s[i] += s[p[i]] / 2;
	}
	int q;
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		--u, --v;
		if(s[u] > s[v]){
			cout << "FIRST\n";
		}else if(s[u] < s[v]){
			cout << "SECOND\n";
		}else{
			cout << "TIE\n";
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
