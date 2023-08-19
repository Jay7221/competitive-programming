#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';}cerr << '\n';
class ZigZag
{
public:
	int longestZigZag(vector<int>& a){
		int n = a.size();
		// dp1[i] = maximum length of a zig zag sequence ending at i with positive difference
		// dp2[i] = maximum length of a zig zag sequence ending at i with a negative difference
		vector<int> dp1(n, 1), dp2(n, 1);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j){
				if(a[i] == a[j])
					continue;
				else if(a[j] < a[i]){
					dp1[i] = max(dp1[i], 1 + dp2[j]);
				}else{
					dp2[i] = max(dp2[i], 1 + dp1[j]);
				}
			}
		}
		return max(dp1[n - 1], dp2[n - 1]);
	}
};
int main(){
	int k ;
	vector<int> a;
	while(cin >> k){
		a.push_back(k);
	}
	ZigZag z;
	cout << z.longestZigZag(a) << '\n';
}