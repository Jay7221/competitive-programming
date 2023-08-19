#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> s(n), x0(n), x1(n);
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		s[i] = ch - '0';
	}
	x1[0] = 1;
	for(int i = 1; i < n; ++i){
		x0[i] = x0[i - 1] ^ s[i - 1];
		x1[i] = x1[i - 1] ^ s[i - 1];
	}
	int sum0 = accumulate(x0.begin(), x0.end(), 0);
	int sum1 = accumulate(x1.begin(), x1.end(), 0);
	cout << max(sum0, sum1) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}
}
