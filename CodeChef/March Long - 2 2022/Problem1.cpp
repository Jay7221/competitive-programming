#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll a, ll b, ll c, ll d){
	ll x = (a + b) / 2;
	ll y = (a - b) / 2;
	if(x + y != a){
		return 0;
	}
	if(x - y != b){
		return 0;
	}
	if(x * y != c){
		return 0;
	}
	if(y == 0 || x / y != d){
		return 0;
	}
	if(x < 1 || x > 1e4){
		return 0;
	}
	if(y < 1 || y > 1e4){
		return 0;
	}
	cout << x << ' ' << y << '\n';
	return 1;
}
void solve(){
	ll data[4];
	cin >> data[0] >> data[1] >> data[2] >> data[3];
	int arr[4] = {0, 1, 2, 3};
	for(int i = 0; i < 24; i++){
		if(check(data[arr[0]], data[arr[1]], data[arr[2]], data[arr[3]]))
			return ;
		next_permutation(arr, arr + 4);
	}
	cout << -1 << ' ' << -1 << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}