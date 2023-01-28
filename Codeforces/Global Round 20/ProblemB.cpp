#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string s;
	cin >> s;
	bool good = 1;
	int a = 0, b = 0;
	for(auto c : s){
		if(c == 'A'){
			a++;
			good = 0;
		}
		else{
			b++;
			if(b > a){
				good = 0;
				break;
			}
			good = 1;
		}
	}
	if(good)
		cout << "YES\n";
	else
		cout << "NO\n";
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