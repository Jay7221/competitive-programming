#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll r, c;
	cin >> r >> c;
	cout << "..";
	cout << '+';
		for(int j = 1; j < c; j++){
			cout << "-+";
		}
		cout << '\n';
	cout << '.';
	for(int j = 0; j < c; j++){
		cout << ".|";
	}
	cout << '\n';
	cout << '+';
		for(int j = 0; j < c; j++){
			cout << "-+";
		}
		cout << '\n';
	for(int i = 1; i < r; i++){
		cout << "|";
		for(int j = 0; j < c; j++){
			cout << ".|";
		}
		cout << '\n';
		cout << '+';
		for(int j = 0; j < c; j++){
			cout << "-+";
		}
		cout << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ":\n";
		solve();
	}
}