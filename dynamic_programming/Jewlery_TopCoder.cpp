#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx (int)(1e5 + 7)
#define debug(a, k) for(auto c : a){cerr << c << ' '; if(!(k--)){break ;}}cerr << '\n';
vector<vector<ll> > COM(1007, vector<ll>(1007));
ll com(int n, int m){
	if(COM[n][m])
		return COM[n][m];
	if(n < m)
		return 0;
	if(n == m)
		return 1;
	if(m == 0)
		return 1;
	return COM[n][m] = (com(n - 1, m) + com(n - 1, m - 1));
}
class Jewelry{
public:
	ll howMany(vector<int>& a){
		int n = a.size();
		sort(a.begin(), a.end());
		a.insert(a.begin(), 0);
		vector<vector<ll> > dp1(n + 2, vector<ll>(mx)), dp2(n + 2, vector<ll>(mx));
		// dp1[i][m] = number of ways to get sum m using first i elements
		// dp2[i][m] = nubmer of ways to get sum m using last i elements
		dp1[0][0] = 1;
		dp2[n + 1][0] = 1;
		for(int i = 1; i < n + 1; ++i){
			for(int m = 0; m < mx; ++m){
				dp1[i][m] += dp1[i - 1][m];
				if(a[i] <= m){
					dp1[i][m] += dp1[i - 1][m - a[i]];
				}
			}
		}
		for(int i = n; i > 0; --i){
			for(int m = 0; m < mx; ++m){
				dp2[i][m] += dp2[i + 1][m];
				if(a[i] <= m){
					dp2[i][m] += dp2[i + 1][m - a[i]];
				}
			}
		}
		ll ans = 0;
		vector<vector<ll> > dpa(n + 2, vector<ll>(mx, 0));
		vector<vector<ll> > dpb(n + 2, vector<ll>(mx, 0));
		for(int i = 1; i < n + 1; ++i){
			for(int m = 0; m < mx; ++m){
				if(m < a[i])
					continue ;
				dpa[i][m] += dp1[i - 1][m - a[i]];
			}
		}
		for(int i = 1; i < n + 1; ++i){
			for(int m = 0; m < mx; ++m){
				if(m < a[i])
					continue ;
				dpb[i][m] += dp2[i + 1][m - a[i]];
			}
		}
		for(int i = 1; i < n; ++i){
			int G = 1;
			int j = i;
			while((j + 1 <= n) && (a[i] == a[j + 1])){
				++j;
			}
			G = j - i + 1;
			for(int g = 1; g < G + 1; ++g){
				for(int m = g * a[i]; m < mx; ++m){
					ans += com(G, g) * dp1[i - 1][m - g * a[i]] * dp2[i + g][m];
				}
			}
			i = j;
		}
		return ans;
	}
};
int main(){
	Jewelry j;
	vector<int> a = {1,2,5,3,4,5};
	cout << j.howMany(a) << '\n';
}