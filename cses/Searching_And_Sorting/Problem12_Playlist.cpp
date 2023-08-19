#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i < n + 1 ;i++){
		cin >> a[i];
	}
	vector<int> pre(n + 2, 0), suf(n + 2, 0);
	map<int, bool> not_uniq;
	for(int i = 1; i < n + 1; i++){
		if(not_uniq[a[i]]){
			not_uniq.clear();
			not_uniq[a[i]] = 1;
			pre[i] = 1;
		}else{
			pre[i] = pre[i - 1] + 1;
			not_uniq[a[i]] = 1;
		}
	}
	not_uniq.clear();
	for(int i = n; i > 0; i--){
		if(not_uniq[a[i]]){
			not_uniq.clear();
			not_uniq[a[i]] = 1;
			suf[i] = 1;
		}else{
			not_uniq[a[i]] = 1;
			suf[i] = suf[i + 1] + 1;
		}
	}
	// for(auto c : pre)
	// 	cerr << c << ' ' ;
	// cerr << '\n';
	// for(auto c : suf)
	// 	cerr << c << ' ';
	int ans = 0;
	for(int i = 1 ;i < n + 1; i++){
		ans = max(ans, max(pre[i], suf[i]));
	}
	cout << ans << '\n';
}