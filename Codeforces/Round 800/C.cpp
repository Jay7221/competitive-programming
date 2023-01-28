#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	ll cur = 0;
	bool pos = 1;
	bool flag = 0;
	for(int i = n - 1; i > -1; --i){
		cur += a[i];
		if(cur != 0){
			flag = 1;
		}
		if(cur > 0){
			pos = 0;
			break ;
		}else if(cur == 0 && i != 0 && flag){
			pos = 0;
			break ;
		}
	}
	if(cur != 0){
		pos = 0;
	}
	if(pos){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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