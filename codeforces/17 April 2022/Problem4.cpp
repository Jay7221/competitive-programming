#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; i++)
		cin >> c[i];
	vector<bool> a(n , 1);
	for(int i = 0; i < n; i++){
		if(c[i] > i && a[i] != 0 && c[i] < n){
				a[c[i]] = 0;
		}else{
			if(c[i] + i < n)
				a[c[i] + i] = 0;
		}
	}
	for(auto c : a)
		cout << c << ' ';
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}