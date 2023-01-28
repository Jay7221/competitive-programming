#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	bool flag = true;
	vector<bool> change(n);
	for(int i = 0; i < n; ++i){
		if(a[i] < b[i]){
			change[i] = 1;
			a[i] = b[i];
		}else if(a[i] > b[i]){
			flag = false;
			break ;
		}
	}
	int cnt = 2 * n + 2;
	for(int cur = 0, next = 1; cnt--; cur = ((cur + 1) % n), next = ((next + 1) % n)){
		if(change[cur]){
			if(a[next] < a[cur] - 1){
				change[next] = 1;
				a[next] = a[cur] - 1;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		if(a[i] != b[i]){
			flag = false;
			break ;
		}
	}
	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}