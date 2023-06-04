#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n;
	cin >> n;
	vector<ll> index_p(n), index_q(n), p(n), q(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
		--p[i];
		index_p[p[i]] = i;
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> q[i];
		--q[i];
		index_q[q[i]] = i;
	}
	auto numSub = [&](ll s)
	{
		if(s <= 0)
		{
			return 0ll;
		}
		return ((s * (s + 1)) / 2); 
	};
	auto isIn = [&](ll ind, ll l, ll r)
	{
		return ((l <= ind) && (ind <= r));
	};
	
	ll ml = min(index_p[0], index_q[0]);
	ll mr = max(index_p[0], index_q[0]);
	ll ans = numSub(ml) + numSub(n - (mr + 1)) + numSub(mr - ml - 1);
	for(int mex = 1; mex < n; ++mex)
	{
		ml = min({ml, index_p[mex - 1], index_q[mex - 1]});
		mr = max({mr, index_p[mex - 1], index_q[mex - 1]});
		ll px = index_p[mex], qx = index_q[mex];
		if(isIn(px, ml, mr) || isIn(qx, ml, mr))
		{
			continue;
		}
		ll l = 0, r = n - 1;
		if(px < ml)
		{
			l = max(l, px + 1);
		}
		if(qx < ml)
		{
			l = max(l, qx + 1);
		}
		if(px > mr)
		{
			r = min(r, px - 1);
		}
		if(qx > mr)
		{
			r = min(r, qx - 1);
		}
		ll tmp = (ml - l + 1) * (r - mr + 1);
		ans += tmp;
	}
	++ans;
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}