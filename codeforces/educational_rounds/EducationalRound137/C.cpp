#include<iostream>
using namespace std;
#define debug(a) for(int i = 0; i < n; ++i){cerr << a[i] << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	int a[n];
	int b[n];
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		b[i] = s[i] - '0';
	}
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long ans = 0, tmp = 0;
	for(int i = 0; i < n; ++i){
		if(b[i]){
			if(a[i] < tmp){
				ans += tmp;
				tmp = a[i];
			}else{
				ans += a[i];
			}
		}else{
			tmp = a[i];
		}
	}
	cout << ans << '\n';
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