#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	n = n % 4;
	if(k == 0){
		if(n == 0){
			cout << "Off\n";
		}else{
			cout << "On\n";
		}
	}else if(k == 1){
		if(n == 0){
			cout << "On\n";
		}else{
			cout << "Ambiguous\n";
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