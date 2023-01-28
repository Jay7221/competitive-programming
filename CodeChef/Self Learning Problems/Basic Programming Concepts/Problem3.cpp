#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	int temp;
	while(b){
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void solve(){
	int N, K;
	cin >> N >> K;
	int g = gcd(N, K);
	cout << N / g << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}