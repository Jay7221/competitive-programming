#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string s;
	cin >> s;
	int suspect = 0;
	for(auto c : s){
		switch(c){
			case '1':
				suspect = 1;
				break ;
			case '?':
				suspect += 1;
				break ;
			case '0':
				cout << suspect + 1 << '\n';
				return ;
				break ;
		}
	}
	cout << suspect << '\n';
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