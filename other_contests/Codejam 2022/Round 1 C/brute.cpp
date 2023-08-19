#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n = rand() % 100;
	n = max(n, 1);
	cout << n << '\n';
	while(n--){
		int s = rand() % 10;
		s = max(s, 1);
		for(int i = 0; i < s; i++){
			char c = (rand() % 26) + 'A'; 
			cout << c;
		}
		cout << ' ' ;
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(0));
	int t = rand() % 100;
	if(t == 0)
		t++;
	cout << t << '\n';
	while(t--){
		solve();
	}
}