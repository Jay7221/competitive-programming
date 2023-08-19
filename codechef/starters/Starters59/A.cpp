#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int mx = *max_element(a.begin(), a.end());
	if(a[0] == mx){
		cout << -1 << '\n';
		return ;
	}
	int ind_mx = find(a.begin(), a.end(), mx) - a.begin();
	vector<int> A, B;
	bool flag = false;
	for(auto elem : a){
		if(elem == mx)
			flag = true;
		if(flag)
			A.push_back(elem);
		else
			B.push_back(elem);
	}
	cout << A.size() << '\n';
	for(auto elem : A)
		cout << elem << ' ' ;
	cout << '\n';
	cout << B.size() << '\n';
	for(auto elem : B)
		cout << elem << ' ';
	cout << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}