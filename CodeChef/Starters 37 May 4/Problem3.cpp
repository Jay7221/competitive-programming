#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	int o = 0, z = 0;
	for(int i = 0; i < n; i++){
		bool k;
		cin >> k;
		o += k;
		z += (k ^ 1);
	}
	if(o >= z){
		cout << 1 << '\n';
		return ;
	}else{
		cout << 0 << '\n';
		return ;
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