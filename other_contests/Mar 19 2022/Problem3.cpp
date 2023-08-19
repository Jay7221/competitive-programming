#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ' ;} cerr << '\n';
void solve(){
	int n, m;
	cin >> n >> m;
	int even = 0, odd = 0;
	string s;
	cin >> s;
	int k = 0;
	for(int i = 0; i < n; i++){
		if(s[k] == s[i]){
			continue ;
		}
		int t = (k - i);
		if(t&1){
			odd++;
		}
		else{
			even++;
		}
		k = i;
	}
	int t = (k - n);
	if(t&1){
		odd++;
	}
	else{
		even++;
	}
	int ans = n;
	ans -= odd;
	if(even > m){
		ans -= even - m;
	}
	cout << ans << '\n';
}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}