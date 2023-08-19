#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	int pos = 0, neg = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a == 1)
			pos++;
		else
			neg++;
	}
	int odd = n / 2;
	int even = n - odd;
	int k = odd % 2 + even % 2;
	if(abs(pos - neg) > k){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}
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