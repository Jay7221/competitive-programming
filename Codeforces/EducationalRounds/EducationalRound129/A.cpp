#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	int alice = 0, bob = 0;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		alice = max(alice, a);
	}
	cin >> m;
	while(m--){
		int a;
		cin >> a;
		bob = max(bob, a);
	}
	if(alice == bob){
		cout << "Alice\nBob\n";
	}else if(alice > bob){
		cout << "Alice\nAlice\n";
	}else{
		cout << "Bob\nBob\n";
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