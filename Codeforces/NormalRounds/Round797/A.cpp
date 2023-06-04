#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	n -= 6;
	int h1 = 3, h2 = 2, h3 = 1;
	h1 += n / 3;
	h2 += n / 3; 
	h3 += n / 3;
	if(n % 3 > 0)
		h1 += 1;
	if(n % 3 > 1)
		h2 += 1;
	cout << h2 << ' ' << h1 << ' ' << h3 << '\n';
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