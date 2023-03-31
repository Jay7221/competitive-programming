#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		if(ch == 'A'){
			++a;
		}else if(ch == 'B'){
			++b;
		}else{
			++c;
		}
	}
	int ans = 0;
	int tmp = min(x, a);
	ans += tmp;
	x -= tmp;
	a -= tmp;

	tmp = min(y, b);
	ans += tmp;
	y -= tmp;
	b -= tmp;

	tmp = min(x, c);
	ans += tmp;
	x -= tmp;
	c -= tmp;

	tmp = min(y, c);
	ans += tmp;
	y -= tmp;
	c -= tmp;

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

	return 0;
}
