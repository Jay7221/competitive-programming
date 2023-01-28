#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(2 * n);
	assert(n > 29);
	for(int i = 0; i < 30; i++)
		a[i] = (1 << i);
	for(int i = 30; i < n; i++){
		a[i] = int(1e9) - (n  - 1 - i);
	}
	for(int i = 0; i < n - 1; i++)
		cout << a[i] << ' ';
	cout << a[n - 1] << '\n';
	cout << flush;
	for(int i = 0; i < n; i++){
		cin >> a[i + n];
		assert(a[i + n] > 0);
	}
	ll tot = accumulate(a.begin(), a.end(), 0ull);
	assert(tot % 2 == 0);
	ll tag = tot / 2;
	vector<int> res;
	res.reserve(2 * n);
	for(int i = 2 * n - 1; tag >= (1 << 30); i--){
		assert(tag > a[i]);
		tag -= a[i];
		res.push_back(a[i]);
	}
	for(int i = 0;i < 30; i++){
		if(tag & (1 << i))
			res.push_back((1 << i));
	}
	for(int i = 0; i < int(res.size()) - 1; i++){
	    cout << res[i] << ' ';
	}
	cout << res[res.size() - 1] ;
	cout << '\n';
	cout << flush;

}
int main(){
	int t;
	cin >> t;
	assert(t > 0);
	for(int i = 1; i < t + 1; i++){
		solve();
	}
}