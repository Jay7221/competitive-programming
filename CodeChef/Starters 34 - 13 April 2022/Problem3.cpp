#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	// cerr << n << '\n' << s << '\n';
	if(n % 2){
		cout << "NO\n";
		return ;
	}
	vector<int> ones(n, 0), zeroes(n, 0);
	if(s[0] == '0')
		zeroes[0] = 1;
	else
		ones[0] = 1;
	for(int i = 1; i < n ; i++){
		ones[i] = ones[i - 1], zeroes[i] = zeroes[i - 1];
		if(s[i] == '1')
			ones[i]++;
		else
			zeroes[i]++;
	}
	cout << "YES\n";
	int k = ones[n - 1] - zeroes[n - 1];
	if(k == 0){
		cout << 1 << ' ' << n  << '\n';
		return ;
	}
	for(int i = 0; i < n; i++){
		if(ones[i] - zeroes[i] == k / 2){
			cout << 1 << ' ' << i + 1<< '\n';
			return ;
		}
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
}