#include<bits/stdc++.h>
using namespace std;
void print(int n, bool k){
	for(int i = 0; i < n; i++){
		cout << k ;
	}
}
void solve(){
	int n;
	cin >> n;
	int ones = 0, zeroes = 0;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++){
		bool k = s[i] - '0';
		ones += k ^ 0;
		zeroes += k ^ 1;
	}
	if(ones > zeroes){
		int a = ones / (zeroes + 1);
		int b = ones % (zeroes + 1);
		int i = 0; 
		while(i < n){
			print(a + (b != 0), 1);
			i += a + (b != 0);
			b -= (b != 0);
			if(i < n){
				cout << 0;
				i += 1;
			}
		}
		cout << '\n';
		print(zeroes, 0);
		print(ones, 1);
	}
	if(ones < zeroes){
		int a = zeroes / (ones + 1);
		int b = zeroes % (ones + 1);
		int i = 0; 
		while(i < n){
			print(a + (b != 0), 0);
			i += a + (b != 0);
			b -= (b != 0);
			if(i < n){
				cout << 1;
				i += 1;
			}
		}
		cout << '\n';
		print(ones, 1);
		print(zeroes, 0);
	}
	if(ones == zeroes){
		bool t = 1;
		for(int i = 0; i < n; i++){
			cout << t;
			t ^= 1;
		}
		cout << '\n';
		print(zeroes, 0);
		print(ones, 1);
	}
	cout << '\n';

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}