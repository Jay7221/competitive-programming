#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> indices;
	set<int> b;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		indices[a[i]]++;
		b.insert(a[i]);
	}
	int ans;
	for(auto c : b){
		ans = c;
		if(indices[c] > k){
			break ;
		}
		k -= indices[c];
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}