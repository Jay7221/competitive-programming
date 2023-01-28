#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<bool> a(n), b(n);
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}
	for(int i = 0; i < n;++i){
		char ch;
		cin >> ch;
		b[i] = ch - '0';
	}
	int s = 0;
	for(int i = 0; i < n; ++i)
		s += a[i] ^ b[i];
	if((s > 0) && (s < n)){
		cout << "NO\n";
		return ;
	}
	if((n == 1)){
		if(b[0]){
			cout << "NO\n";
		}else{
			cout << "YES\n";
			if(a[0]){
				cout << "1\n1 1\n";
			}else{
				cout << "0\n";
			}
		}
		return ;
	}
	bool flag = (s == n);
	bool tmp = 0;
	vector<pair<int, int > > v;
	for(int i = 0; i < n; ++i){
		if(a[i] ^ tmp){
			tmp ^= 1;
			flag ^= 1;
			v.push_back({i + 1, n});
		}
	}
	if(flag){
		v.push_back({1, 1});
		v.push_back({2, n});
		v.push_back({1, n});
	}
	cout << "YES\n";
	cout << v.size() << '\n';
	for(auto [l, r] : v)
		cout << l << ' ' << r << '\n';
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