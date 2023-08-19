#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	if(n % 2 == 0){
		cout << -1 << '\n';
		return ;
	}
	int k = 30;
	while((n & (1 << k)) == 0){
		--k;
	}
	vector<int> v;
	while(k > 0){
		if((n >> k) & 1){
			v.push_back(2);
		}else{
			v.push_back(1);
		}
		--k;
	}
	cout << v.size() << '\n';
	for(int elem : v){
		cout << elem << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
