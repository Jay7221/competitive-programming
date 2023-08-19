#include<bits/stdc++.h>
using namespace std;
#define fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi std::vector<int>
#define vb std::vector<bool>
void solve(){
	int n;
	cin >> n;
	int z = 0, o = 0;
	char c;
	for(int i = 1; i <= n; i++){
		cin >> c;
		if(c == '1'){
			o++;
		}
		else{
			z++;
		}
	}
	while(z--){
		cout << '0' ;
	}
	while(o--){
		cout << '1';
	}
	cout << '\n';


}
int main(){
	fast_
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}