#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<pair<int, int>> type1;
    vector<tuple<int, int, int>> type2;
    bool flag = true;
    if(a[n - 2] > a[n - 1]){
        flag = false;
        for(int i = 0; i < n - 2; ++i){
            if(a[i] > a[n - 2]){
                swap(a[i], a[n - 1]);
                type1.push_back({i, n - 1});
                flag = true;
                break;
            }
        }
        if(!flag){
            for(int i = 0; i < n - 3; ++i){
                if(a[i] < a[n - 1]){
                    swap(a[i], a[n - 2]);
                    type1.push_back({i, n - 2});
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            if(n > 3){
                flag = true;
                type1.push_back({0, n - 1});
                type1.push_back({0, n - 2});
                swap(a[0], a[n - 1]);
                swap(a[0], a[n - 2]);
            }
        }
    }

    if(flag){
        int j = n - 2, k = n - 1;
        int y = j, z = k;
        for(int i = n - 3; i >= 0; --i){
            if(a[i] > a[j]){
                type2.push_back({i, y, z});
                --y, --z;
            }else{
                j = i;
                y = i;
            }
        }
    }

    if(flag){
        cout << "YES\n";
        cout << (type1.size() + type2.size()) << ' ' << (type1.size()) << '\n';
        for(auto [u, v] : type1){
            ++u, ++v;
            cout << 1 << ' ' << u << ' ' << v << '\n';
        }
        for(auto [u, v, w] : type2){
            ++u, ++v, ++w;
            cout << 2 << ' ' << u << ' ' << v << ' ' << w << '\n';
        }
    }else{
        cout << "NO\n";
    }
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

    return 0;
}
