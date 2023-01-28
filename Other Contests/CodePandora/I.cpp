#include<iostream>
using namespace std;
void solve()
{
    int h;
    cin >> h;
    if(h > 8)
    {
        cout << "REAL";
    }
    else
    {
        cout << "FAKE";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}