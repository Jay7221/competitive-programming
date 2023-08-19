#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1e6
void solve(){
	int N ;
	cin >> N;
	int a[N];
	for(int i = 0; i < N;i++){
		cin >> a[i];
	}
	int p = mx, q = mx, j;
	for(int i = 0; i < N; i++){
		if(p > a[i]){
			p = a[i];
			j = i;
		}
	}
	for(int i = 0; i < N; i++){
		if(j != i){
			q = min(q, a[i]);
		}
	}
	cout << p + q << "\n";
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