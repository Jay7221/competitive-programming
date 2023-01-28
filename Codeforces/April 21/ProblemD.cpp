#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
bool check(int r, int b){
	if(r == 0 && b == 0)
		return 1;
	if(r == 0 || b == 0){
		cout << "NO\n";
		return 0;
	}
	return 1;
}
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int red = 0, blue = 0;
	for(int i = 0; i < n; i++){
		switch(s[i]){
			case 'R':
				red++;
				break;
			case 'B':
				blue++;
				break;
			case 'W':
				if(!check(red, blue))
					return ;
				red = 0, blue = 0;
		}
	}
	if(!check(red, blue))
		return ;
	cout << "YES\n";
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