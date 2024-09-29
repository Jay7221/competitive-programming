#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);
    for(int i = 0; i < n; ++i){
        cin >> start[i];
    }
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> end[i];
    }

    vector<tuple<int, int, int>> ranges;
    for(int i = 0; i < n; ++i){
        ranges.push_back({start[i], end[i], i});
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    vector<int> res(n);
    for(auto [l, r, i]: ranges){
        int after = upper_bound(start.begin(), start.end(), r) - start.begin();
        after = n - after;
        int before = lower_bound(end.begin(), end.end(), l) - end.begin();
        res[i] = n - after - before - 1;
    }

    for(int i = 0; i < n; ++i){
        cout << res[i] << '\n';
    }
    return 0;
}
 
