#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx (ll)(1e6)
void solve(){
	ll c, m, y, k;
	c = m = y = k = mx + 10;
	for(int i = 0; i < 3; i++){
		ll temp;
		cin >> temp;
		c = min(c, temp);
		cin >> temp;
		m = min(m, temp);
		cin >>temp;
		y = min(y, temp);
		cin >> temp;
		k = min(k, temp);
	}
	ll sum = c + m + y + k;
	if(sum < mx){
		cout << "IMPOSSIBLE";
		return ;
	}
	while(sum > mx){
		if(k > sum - mx){
			k -= sum - mx;
			sum = mx;
			break ;
		}
		sum -= k;
		k = 0;
		if(y > sum - mx){
			y -= sum - mx;
			sum = mx;
			break ;
		}
		sum -= y;
		y = 0;
		if(m > sum - mx){
			m -= sum - mx;
			sum = mx;
			break ;
		}
		sum -= m;
		m = 0;
		if(c > sum - mx){
			c -= sum - mx;
			sum = mx;
			break ;
		}
		sum -= c;
		c = 0;
	}
	cout << c << ' ' << m << ' ' << y << ' ' << k ;
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << '\n';
	}
}