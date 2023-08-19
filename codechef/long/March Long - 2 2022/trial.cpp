#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 100;
	for(int i = 1; i < sqrt(n); i++){
		cout << i << '\n';
		n /= i;
	}
}