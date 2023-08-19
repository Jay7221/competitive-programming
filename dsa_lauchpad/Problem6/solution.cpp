#include<bits/stdc++.h>
using namespace std;
void solve(){
	int dum1, dum2, dum3;
	cin >> dum1 >> dum2 >> dum3;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = n - 1; i > -1; --i)
		cout << a[i] << ' ';
}
int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("solution.txt", "w", stdout);
	}
	solve();
	return 0;
};
