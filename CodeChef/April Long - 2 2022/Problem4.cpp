#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(is_sorted(a.begin(), a.end())){
		cout << "YES\n";
		return ;
	}
	for(int i = 0; i < n - 1; i++){
		if(a[i] > a[i + 1]){
			swap(a[i], a[i + 1]);
			if(is_sorted(a.begin(), a.end()))
				cout << "YES\n";
			else
				cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
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