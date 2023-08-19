#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int cur = a[0] % 2;
	for(int i = 0; i < n; i += 2){
		if(a[i] % 2 != cur){
			cout << "NO\n";
			return ;
		}
	}
	cur = a[1] % 2;
	for(int i = 1; i < n; i += 2){
		if(a[i] % 2 != cur){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
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