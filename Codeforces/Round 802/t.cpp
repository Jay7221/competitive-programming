#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 0; i < n + 1 ;++i)
		cin >> a[i];
	if(n % 2){
		for(int i = 1; i< n + 1; ++i)
			cout << (a[i] ^ a[0]) << ' ' ;
		cout << '\n';
		return ;
	}
	int x= 0;
	for(int i = 0; i < n + 1; ++i){
		x ^= a[i];
	}
	for(int i = 0; i < n + 1; ++i)
		a[i] ^= x;
	sort(a.begin(), a.end());
	for(int i = 1; i< n + 1; ++i)
		cout << a[i] << ' ' ;
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