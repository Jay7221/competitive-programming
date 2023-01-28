#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll a, b, c, d;
    ll arr[3];
    cin >> arr[0] >> arr[1] >> arr[2] >> d;
    int ans;
    sort(arr, arr + 3);
    a = arr[0];
    b = arr[1];
    c = arr[2];
    if((a + b + c) <= d)
    {
        ans = 1;
    }
    else if((a + b) <= d)
    {
        ans = 2;
    }
    else
    {
        ans = 3;
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
