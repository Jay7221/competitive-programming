#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx  (unsigned long int)1e5 + 5
#define mod (int)1e9 + 7
void solve(){
	int n;
	cin >> n;
	if(n < 3){
		cout << "NO" << "\n";
		return ; 
	}
	ll a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int i = 2, j = n - 2;
	ll s1 = a[0] + a[1];
	ll s2 = a[n - 1];
	if(s1 < s2){
		cout << "YES" << "\n";
		return ;
	}
	while(i < j){
		s1 += a[i];
		s2 += a[j];
		if(s1 < s2){
			cout << "YES" << "\n";
			return ;
		}
		i++;
		j--;
	}
	cout << "NO" << "\n";
}
int main() {
	// your code goes here
	cout << "Hello World" << "\n";
}
