#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int A[n], B[n];
	for(int i = 0; i < n; ++i){
		cin >> A[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> B[i];
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += max({0, A[i], B[i], A[i] + B[i] - A[i] * B[i]});
	}
	cout << ans;
}