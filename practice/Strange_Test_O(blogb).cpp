#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int a, b;
	cin >> a >> b;
	int ans = b - a;
	for(int a2 = a; a2 < b; a2++){
		int b2 = 0;
		int p = (1 << 25);
		while(p > 0){
			if(b & p){
				b2 += p;
			}else if(a2 & p){
				b2 += p;
				break ;
			}
			p = (p >> 1);
		}
		ans = min(ans, a2 + (a2 | b2) + (1 - a - b));
	}
	cout << ans << '\n';
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