#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	int b[n];
	vi has;
	bool possible = 1;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		if(b[i] > i + 1){
			possible = 0;
			continue ;
		}
		if(b[i] != -1){
			if(!has.empty() && has.back() > b[i]){
				possible = 0;
				continue ;
			}
			if(!has.empty() && has.back() == b[i]){
				b[i] = -1;
				continue ;
			}
			has.push_back(b[i]);
		}
	}
	if(!possible){
		cout << -1 << '\n';
		return ;
	}
	int a[n + 10];
	for(int i = 0; i < n + 10; i++){
		a[i] = i ;
	}
	for(auto c : has){
		a[c] = -1;
	}
	int ans[n];
	int j = 0, k = 0;
	while(a[j] == -1){j++;}
	for(int i = 0; i < n; i++){
		if(b[i] == -1 || b[i] == has[k]){
			ans[i] = a[j];
			j++;
			while(a[j] == -1){j++;}
		}
		else{
			ans[i] = has[k];
			k++;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}