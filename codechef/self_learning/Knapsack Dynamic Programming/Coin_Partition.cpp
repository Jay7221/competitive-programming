#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(510)
int a[mx], pre[mx][mx * mx], suf[mx][mx * mx];
int n, tot;
int getans(int pos){
	tot -= a[pos];
	int req = tot / 2;
	int ans = 0;
	for(int i = 0; i < req + 1; ++i){
		if(!pre[pos - 1][i])
			continue;
		int j = req - i;
		while(j >= 0 && !suf[pos + 1][j])
			--j;
		if(j < 0)
			continue ;
		ans = max(ans, i + j + a[pos]);
	}
	tot += a[pos];
	return ans;
}
void make_ans(int x, int ind){
	vector<bool> last(x + 1), pos(x + 1);
	pos[0] = 1;
	x -= a[ind];
	for(int i = 1; i < n + 1; ++i){
		if(i == ind)
			continue ;
		for(int j = x; j > 0; ++j){
			if(j - a[i] >= 0 && !pos[j] && pos[j - a[i]])
				pos[j] = 1, last[j] = i;
		}
	}
	set<int> p, q;
	for(int i = 1; i < n + 1; ++i)
		p.insert(i);
	int tmp = x;
	while(tmp != 0){
		int k = last[tmp];
		tmp -= k;
		p.erase(k), q.insert(k);
	}
	vector<int> A;
}
void solve(){
	cin >> n;
	for(int i = 1; i < n + 1; ++i)
		cin >> a[i];
	tot = accumulate(a + 1, a + n + 1, 0);
	pre[0][0] = 1;
	int sumi = 1;
	for(int i = 1; i < n + 1; ++i){
		sumi += a[i];
		for(int j = 0; j < sumi; ++j){
			pre[i][j] = pre[i - 1][j];
			if(j - a[i] >= 0)
				pre[i][j] |= pre[i - 1][j - a[i]];
		}
	}
	suf[n + 1][0] = 1;
	sumi = 1;
	for(int i = n; i > 0; --i){
		sumi += a[i];
		for(int j = 0; j < sumi; ++j){
			suf[i][j] = suf[i + 1][j];
			if(j - a[i] >= 0)
				suf[i][j] |= suf[i + 1][j - a[i]];
		}
	}
	int fans = 0, ind = 0;
	for(int i = 1; i < n + 1; ++i){
		int tmp = getans(i);
		if(tmp > fans){
			fans = tmp;
			ind = i;
		}
	}
	make_ans(fans, ind);
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
}