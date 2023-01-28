#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0;i < n ;i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vi even, odd;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a&1)		odd.push_back(a);
		else		even.push_back(a);
	}
	int es = even.size(), os = odd.size();
	if(os == 0){		// if there are no odd elements
		cout << -1 << '\n';
		return ;
	}
	if(os == 1 && es > 0){		// if there only one odd element and no even elements
		cout << -1 << '\n';
		return ;
	}
	if(os == 1 && es == 0){		// if there is only one odd element and one or more even elements
		cout << odd[0] << '\n';
		return ;
	}
	if(os % 2 == 1 && es == 0){		// if number of odd elements is odd and there are no even elements
		cout << -1 << '\n';
		return ;
	}
	if(os % 2 == 1 && es > 0){	// if number of odd elements is odd and there is one or more even elements
		cout << odd[0] << ' ';
		for(auto c : even){
			cout << c << ' ';
		}
		for(int i = 1; i < os; i++){		
			cout << odd[i] << ' ';
		}
		return ;
	}
	if(os % 2 == 0){		// if number of odd elements is even
		for(auto c : odd){
			cout << c << ' ';
		}
		for(auto c : even){
			cout << c << ' ';
		}
		cout << '\n';
		return ;
	}

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}