#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve(){
	int N ;
	cin >> N;
	int a[N];
	int p = 0, q = 0;
	for(int i = 0; i < N; i++){
		cin >> a[i];
		if(a[i] > 0){
			p++;
		}
		else{
			q++;
		}
	}
	cout << max(p, q) << "\n";
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int N;
	while(T--){
		solve();
	}
	return 0;
}
