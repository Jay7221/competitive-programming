#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    map<char, int> dist;
    dist['A'] = 0;
    dist['B'] = 3;
    dist['C'] = 4;
    dist['D'] = 8;
    dist['E'] = 9;
    dist['F'] = 14;
    dist['G'] = 23;
    char p, q;
    cin >> p >> q;
    cout << abs(dist[p] - dist[q]) << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    return 0;
}
