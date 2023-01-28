#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(a, n) for(int i = 0;i < n; i++){cerr << i << '\t' << a[i] << '\n';} cerr << '\n';
int inf_people[25];
void pre(){
	inf_people[0] = 1;
	for(int i = 1; i <= 10; i++){
		inf_people[i] = 2 * inf_people[i - 1];
	}
	for(int i = 11; i < 30; i++){
		inf_people[i] = 3 * inf_people[i - 1];
	}
}
void solve(){
	int n, d;
	cin >> n >> d;
	if(d > 20){
		cout << n << '\n';
	}
	else{
		cout << min(n, inf_people[d]) << '\n';
	}
}
int main(){
	fast_io
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}