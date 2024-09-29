#include <bits/stdc++.h>
 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
    null_type,
    std::less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

 
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

    sort(ranges.begin(), ranges.end());

    vector<int> res(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    ordered_set st;
    for(int i = 0; i < n; ++i){
        st.insert(make_pair(start[i], i + 1));
    }

    for(auto [start, end, ind]: ranges){
        while(!pq.empty() && (pq.top() < start)){
            pq.pop();
        }
        res[ind] = pq.size() + st.order_of_key(make_pair(end + 1, 0)) - st.order_of_key(make_pair(start, 0)) - 1;
        pq.push(end);
    }

    for(int i = 0; i < n; ++i){
        cout << res[i] << '\n';
    }


    return 0;
}
 
