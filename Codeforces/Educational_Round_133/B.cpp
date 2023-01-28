#include<bits/stdc++.h>
using namespace std;
void solve(){
	auto print = [&](vector<int>& a){
		for(auto c : a)
			cout << c << ' ';
		cout << '\n';
	};
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		a[i] = i + 1;
	int cur = 0;
	cout << n << '\n';
	print(a);
	for(int i = 0; i < n - 1; ++i){
		swap(a[cur], a[cur + 1]);
		++cur;
		print(a);
	}
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