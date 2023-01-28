#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x;
	vector<int> doors(4);
	cin >> x;
	for(int i = 1; i < 4; ++i){
		cin >> doors[i];
	}
	int cnt = 0;
	while(x){
		x = doors[x];
		++cnt;
	}
	if(cnt == 3){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}