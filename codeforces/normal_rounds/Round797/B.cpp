#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		a[i] -= b[i];
	}
	int moves = *max_element(a.begin(), a.end());
	bool flag = 1;
	for(int i = 0; i < n; ++i){
		if(a[i] < 0){
			flag = 0;
			break ;
		}
		else if((a[i] < moves) && (b[i] != 0)){
			flag = 0;
			break ;
		}
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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