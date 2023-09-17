#include <bits/stdc++.h>
 
using namespace std;

#define pii pair<int, int>

int minimumAmount(int C, int D, int F, int N, int dis[][2]){
    int n = N;
    vector<int> dist(n + 1), price(n + 1);
    price[0] = F;
    for(int i = 1; i <= n; ++i){
        dist[i] = dis[i - 1][0] / 100;
        price[i] = dis[i - 1][1];
    }
    D /= 100;

    multiset<int> m;
    m.insert(price[0]);
    int l = 0, r = 1;
    int ans = 0;
    for(int d = 1; d <= D; ++d){
        ans += *m.begin();
        while(r <= n){
            if(dist[r] > d){
                break;
            }
            m.insert(price[r]);
            ++r;
        }
        while(l < n){
            if(d - dist[l] < C){
                break;
            }
            m.erase(m.find(price[l]));
            ++l;
        }
    }

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int C, D, F;
    cin >> C >> D >> F;


    int n;
    cin >> n;
    int dis[n][2];
    for(int i = 0; i < n; ++i){
        cin >> dis[i][0] >> dis[i][1];
    }
    cout << minimumAmount(C, D, F, n, dis);

    return 0;
}
 
