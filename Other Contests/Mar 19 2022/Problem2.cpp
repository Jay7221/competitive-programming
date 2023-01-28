#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	std::vector<char> ans;
	int k = (n - 1)/ 2;
	while(k >= 0){
		ans.push_back(s[k]);
		ans.push_back(s[n - 1 - k]);
		k--;
	}
	for(auto c : ans){
		cout << c;
	}
	cout << '\n';

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}