#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << '\n';
	}
	else if(n % 2 == 1){
		cout << -1 << '\n';
	}else{
		vector<int> p(n);
		int cur = n - 1;
		for(int i = 0; i < n; i += 2){
			p[i] = cur;
			cur -= 2;
		}
		cur = n;
		for(int i = 1; i < n; i += 2){
			p[i] = cur;
			cur -= 2;
		}
		for(int i = 0; i < n; ++i){
			cout << p[i] << ' ';
		}
		cout << '\n';
	}
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
	
	return 0;
}