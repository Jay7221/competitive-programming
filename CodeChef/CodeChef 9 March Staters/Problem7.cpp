#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vf vector<double>
#define mod (int)(1e9 + 7)
void solve(){
	// code to solve each test case
	int n, m, q;
	cin >> n >> m >> q;
	string s;
	cin >> s;
	int num = 0;
	int i = 0;
	vi pos_ones;
	while(i < n){
		if(s[i] == '1'){
			pos_ones.push_back(n - i);
			while(i < n &&  s[i] == '1'){
				i++;
			}
		}
		if(s[i] == '0'){
			while(i < n && s[i] == '0'){
				i++;
			}
		}
	}
	for(int j = 1; j <= q; j++){
		int x; 
		cin >> x;
		if(x == 1 && (-j <= i)){
			num++;
			i = -j - m;
		}
		cout << num << '\n';
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; 			// total number of text cases
	cin >> T;
	while(T--){
		solve();
	}
}