#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void calc(vector<int> a){
	int ans = 0;
	for(int i = 0; i < a.size(); i++){
		if(abs(a[i] - i - 1) == 0){
			ans = -1;
			break ;
		}
		ans ^= abs(a[i] - i - 1);
	}
	if(ans != 0)
		return ;
	for(auto c : a)
		cout << c << ' ' ;
	cout <<  "  :      " ;
	cout << ans << '\n';

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> a = {1, 2, 3, 4, 5, 6, 7};
	for(int i = 0; i < 2 * 3 * 4 * 5 * 6 * 7; i++){
		calc(a);
		next_permutation(a.begin(), a.end());
	}

}