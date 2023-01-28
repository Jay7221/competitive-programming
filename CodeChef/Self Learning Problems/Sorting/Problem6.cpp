#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1e6
void solve(){
	int n;
	cin >> n;
	map<ll, ll> m1, m2;
	for(int i = 0; i < 4 * n - 1; i++){
		ll x, y;
		cin >> x >> y ;
		m1[x]++;
		m2[y]++;
	}
	ll x, y;
	for(auto i : m1){
		if(i.second % 2){
			x = i.first;
		}
	}
	for(auto i : m2){
		if(i.second % 2){
			y = i.first;
		}
	}
	cout  << x << " " << y << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}