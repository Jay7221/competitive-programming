#include<bits/stdc++.h>
using namespace std;
#define ll long long
int query(ll a, ll b){
	cout << "? " << a << ' ' << b << '\n';
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
void print(ll ans){
	cout << "! " << ans  << '\n';
	fflush(stdout);
}
ll get_win(ll a, ll b, ll c, ll d){
	int x = query(a, c);
	if(x == 0){
		if(query(b, d) == 1){
			return b;
		}else{
			return d;
		}
	}else if(x == 1){
		if(query(a, d) == 1){
			return a;
		}else{
			return d;
		}
	}else{
		if(query(c, b) == 1){
			return c;
		}else{
			return b;
		}
	}
}
void proc(stack<ll>& st){
	ll a, b, c, d;
	a = st.top();
	st.pop();
	b = st.top();
	st.pop();
	c = st.top();
	st.pop();
	d = st.top();
	st.pop();
	st.push(get_win(a, b, c, d));
}
void solve(){
	int n;
	cin >> n;
	if(n == 1){
		if(query(1, 2) == 1){
			print(1);
		}else{
			print(2);
		}
		return ;
	}
	ll cur = 1;
	stack<ll> st;
	ll k = 4;
	ll step = 0;
	ll mx = (1ll << n);
	// cout << mx << '\n';
	while(cur + 3 < mx + 1){
		// cout << "!!!!!!!!!!! " << cur << '\n';
		st.push(get_win(cur, cur + 1, cur + 2, cur + 3));
		++step;
		cur += 4;
		for(int i = 2; (1 << i) <= step; i += 2){
			if(step % (1ll << i))
				break ;
			else{
				if(st.size() >= 4)
				proc(st);
			}
		}
	}
	if(st.size() == 2){
		ll a, b;
		a = st.top();
		st.pop();
		b = st.top();
		st.pop();
		if(query(a, b) == 1){
			st.push(a);
		}else{
			st.push(b);
		}
	}
	print(st.top());
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}