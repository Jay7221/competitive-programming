#include<bits/stdc++.h>
using namespace std;
void solve(){
	int dum1, dum2, dum3;
	cin >> dum1 >> dum2 >> dum3;
	int n, k;
	cin >> k;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0, j = k; j <= n; i += k, j += k)
		reverse(a + i, a + j);
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}
int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("solution.txt", "w", stdout);
	}
	solve();
	return 0;
};
