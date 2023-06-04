#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		a[i] = i + 1;
	}
	if(n % 2 == 0){
		for(int i = 0; i < n; i += 2){
			swap(a[i], a[i + 1]);
		}
	}else{
		for(int i = 1; i < n; i += 2){
			swap(a[i], a[i + 1]);
		}
	}
	for(auto c : a){
		cout << c << ' ' ;
	}
	cout << '\n';
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