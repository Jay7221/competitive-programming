#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n, x);
	int i = (n - 1) / 2, j = n / 2;
	int cur = 1;
	for(int i = 0; i < (n / 2) * 2; i++){
		if(i % 2){
			a[i] -= cur;
			cur++;
		}else{
			a[i] += cur;
		}
	}
	for(auto c : a)
		cout << c << ' ' ;
	cout << '\n';
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