#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int a, b;
	cin >> a >> b;
	if(a * 2 == b){
		cout << "ANY\n";
		return ;
	}
	if(a * 2 > b){
		cout << "FIRST\n";
		return ;
	}
	cout << "SECOND\n";
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