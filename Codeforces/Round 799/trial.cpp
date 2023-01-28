#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << '\n';
		cout << 1 << '\n';
		return ;
	}
	if(n % 2){
		cout << -1 << '\n';
		return ;
	}
	vector<int> p(n + 1);
	p[0] = 1;
	for(int i = n; i > 0; --i){
		if(p[i])
			continue; 
		int k = i;
		int tmp = 1;
		while(tmp <= k){
			k ^= tmp;
			tmp <<= 1;
		}
		p[k] = i;
		p[i] = k;
	}
	for(int i = 1; i < n + 1; ++i)
		cout << i << ' ';
	cout << '\n';
	for(int i = 1; i < n + 1; ++i)
		cout << p[i] << ' ' ;
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