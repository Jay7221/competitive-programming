#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	int x, y;
	cin >> x >> y ;
	x = max(0, x - a), y = max(0, y - b);
	if(x + y > c){
		cout << "NO\n";
	}else{
		cout << "YES\n";
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