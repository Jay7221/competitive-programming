#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int mex = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == mex)
			mex++;
	}
	vector<int> b;
	b.push_back(a[0]);
	for(int i = 1; i < n; i++){
		if(a[i] != b.back())
			b.push_back(a[i]);
	}
	n = b.size();
	a = b;
	int ans = 0;
	if(mex == 0){
		cout << a[0] - 1 << '\n';
		return ;
	}
	if(mex == 1){
		cout << -1 << '\n';
		return ;
	}
	int i = 0;
	// for(auto c : a)
	// 	cerr << c << ' ';
	// cerr << '\n';
	while(i < n){
		int consecutive = 1;
		while(i + 1 < n && a[i] + 1 == a[i + 1]){
			i++;
			consecutive++;
		}
		i++;
		// cerr << consecutive << ' ' << a[i] << '\n';
		if(consecutive >= mex - 1)
			ans++;
	}
	cout << ans - 1 << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}