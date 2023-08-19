#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void print(char c, int n){
	for(int i = 0; i < n; i++)
		cout << c ;
}
void solve(){
	int n, r, b;
	cin >> n >> r >> b;
	int k = r / (b + 1);
	int rem = r % (b + 1);
	while(b--){
		print('R', k + (rem > 0));
		rem--;
		cout << "B";
	}
	print('R', k);
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