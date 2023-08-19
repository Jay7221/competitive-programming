#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	ll sum_r = a[0], sum_b = 0;
	int i = 1, j = n - 1;
	while(j > i){
		sum_r += a[i];
		sum_b += a[j];
		if(sum_b > sum_r){
			cout << "YES\n";
			return ;
		}
		i++; j--;
	}
	cout << "NO\n" ;
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