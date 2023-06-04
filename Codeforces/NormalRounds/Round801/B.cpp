#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(n % 2){
		cout << "Mike\n";
		return ;
	}
	ll mike = inf, joe = inf;
	int ind_m = n, ind_j = n;
	for(int i = 0; i < n; i += 2)
		mike = min(mike, a[i]);
	for(int i = 0; i < n; i += 2){
		if(a[i] == mike){
			ind_m = i;
			break; 
		}
	}
	for(int i = 1; i < n; i += 2)
		joe = min(joe, a[i]);
	for(int i = 1; i < n; i += 2){
		if(a[i] == joe){
			ind_j = i;
			break;
		}
	}
	if(mike == joe){
		if(ind_m > ind_j)
			cout << "Mike\n";
		else
			cout << "Joe\n";
		return ;
	}
	if(mike > joe)
		cout << "Mike\n";
	else
		cout << "Joe\n";
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