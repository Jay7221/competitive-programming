#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1e6
bool is_same_arr(int a[], int b[], int n){
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			return 0;
		}
	}
	return 1;
}
void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a, a + n);
	if(is_same_arr(a, b, n)){
		cout << "yes" << '\n';
	}
	else{
		cout << "no" << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}