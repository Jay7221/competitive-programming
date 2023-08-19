#include<iostream>
using namespace std;
void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	bool flag = false;
	if(a == n && b == n)
		flag = true;
	if(a + b < n - 1)
		flag = true;
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";
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
	return 0;
}