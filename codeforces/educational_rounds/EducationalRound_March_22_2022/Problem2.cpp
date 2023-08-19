#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
bool is_square(int a){
	int t = sqrt(a);
	return t * t == a;
}
int min_sum(int n){
	for(int i = 0; i <= sqrt(n); i++){
		if(is_square(n - i * i)){
			cerr << i << ' ' << sqrt(n - i * i) << '\n';
			return i + sqrt(n - i * i);
		}
	}
}
void solve(){
	ll n, b, x, y;
	cin >> n >> b >> x >> y;
	vi a(n + 1);
	a[0] = 0;
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		if(a[i - 1] + x <= b){
			a[i] = a[i - 1] + x;
		}
		else{
			a[i] = a[i - 1] - y;
		}
		sum += a[i];
	}
	cout << sum << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}