#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr <<  c;}cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> s(n), b;
	for(int i = 0; i < n; ++i){
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	reverse(s.begin(), s.end());
	if(s[n - 1] > 7){
		b.resize(n + 1, 1);
	}else{
		b.resize(n , s[n - 1] + 2);
	}
	for(int i = 0; i < n; ++i){
		b[i] -= s[i];
		if(b[i] < 0){
			b[i] += 10;
			--b[i + 1];
		}
	}
	for(int i = n - 1; i > - 1;--i)
		cout<< b[i];
	cout << '\n';
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