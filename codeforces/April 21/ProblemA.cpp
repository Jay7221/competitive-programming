#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int r;
	cin >> r;
	int x = 1;
	if(r >= 1900)
		x = 1;
	if(r < 1900 && r >= 1600)
		x = 2;
	if(r < 1600 && r >= 1400)
		x = 3;
	if(r < 1400)
		x = 4;
	cout << "Division " << x << '\n';
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