#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){
	string I, P;
	cin >> I >> P;
	int n = I.size(), m = P.size();
	int i = 0, j = 0;
	if(m < n){
		cout << "IMPOSSIBLE" << '\n';
		return ;
	}
	while(i < n && j < m){
		if(I[i] == P[j]){
			i++; j++;
			continue ;
		}
		while(j < m && I[i] != P[j]){
			j++;
		}
		i++;   j++;
	}
	if(I[i - 1] != P[j - 1]){
		i--; j--;
	}
	if(i == n){
		cout << m - n << '\n';
	}
	else{
		cout << "IMPOSSIBLE" << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}