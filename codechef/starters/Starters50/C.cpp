#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, x, y;
	cin >> n >> x >> y;
	vector<ll> a(n +  2), X(n + 2), Y(n + 2);
	// X[i] = the total number of moves required if each move decreases sadness by x
	// Y[i] = the total number of moves required if each move decreases sadness by y
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
		X[i] = ceil((double)a[i] / x);
		Y[i] = ceil((double)a[i] / y);
	}
	if(y >= x){
		cout << *max_element(Y.begin(), Y.end()) << '\n';
		// if y >= x, then there is no point in stopping the blimp anywhere
		// we will just let it fly over all the cities
		// in this case for each blimp, the sadness of each city decreases by y
		// thus the total number of blimps required is decided by the city with maximum sadness
		return ;
	}
	// now considering x > y
	// in this case we will stop the blimp at rightmost city with a[i] > 0
	// here we will require ceil(a[i] / x) blimps to make a[i] = 0
	// we continue this process, with the only change that for any subsequent city, "number_blimps" blimps have already passed over it and thus it's current sadness is actually (a[i] - y * number_blimps)
	ll number_blimps = 0;
	for(int i = n; i > 0; --i){
		if(number_blimps * y >= a[i])
			continue ;
		number_blimps += ceil((double)(a[i] - y * number_blimps) / x);
	}
	cout << number_blimps << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}