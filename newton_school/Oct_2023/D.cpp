#include <bits/stdc++.h>
 
using namespace std;

#define ll long long
 
struct Node{
    ll totalSquareSum, totalSum, total;
    ll curSquareSum, curSum, cur;
    Node(int sz = 0){
        total = totalSum = totalSquareSum = sz;
        curSquareSum = curSum = cur = 0;
    }
};
Node merge(Node a, Node b){
    Node res;

    ll d = a.total;

    res.total = a.total + b.total;
    res.totalSum = a.totalSum + b.totalSum + d * b.total;
    res.totalSquareSum = a.totalSquareSum + b.totalSquareSum + 2 * d * b.totalSum + b.total * d * d;

    res.cur = a.cur + b.cur;
    res.curSum = a.curSum + b.curSum + d * b.cur;
    res.curSquareSum = a.curSquareSum + b.curSquareSum + 2 * d * b.curSum + b.cur * d * d;

    return res;
}

struct SegmentTree{
    int n, N;
    vector<Node> tree;
    vector<int> L, R;
    vector<bool> prop;
    SegmentTree(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        N = 2 * n;
        tree = vector<Node>(N);
        L = vector<int>(N);
        R = vector<int>(N);
        prop = vector<bool>(N);
        for(int node = n; node < N; ++node){
            int i = node - n;
            L[node] = R[node] = i;
            tree[node] = Node(1);
        }
        for(int node = n - 1; node >= 0; --node){
            int left = 2 * node;
            int right = 2 * node + 1;
            tree[node] = merge(tree[left], tree[right]);
            L[node] = L[left];
            R[node] = R[right];
        }
    }
    void flip(Node &a){
        a.cur = a.total - a.cur;
        a.curSum = a.totalSum - a.curSum;
        a.curSquareSum = a.totalSquareSum - a.curSquareSum;
    }
    void flip(int node){
        flip(tree[node]);
        prop[node] = true;
    }
    void propogate(int node){
        if(!prop[node]){
            return;
        }
        prop[node] = false;
        int left = 2 * node;
        int right = left + 1;
        if(left < N){
            flip(left);
        }
        if(right < N){
            flip(right);
        }
    }
    void update(int node){
        int left = 2 * node;
        int right = left + 1;
        if((left < N) && (right < N)){
            tree[node] = merge(tree[left], tree[right]);
        }
    }
    Node query(int l, int r, int node = 1){
        if((node >= N) || (R[node] < l) || (r < L[node])){
            return Node(0);
        }
        if((l <= L[node]) && (R[node] <= r)){
            return tree[node];
        }
        propogate(node);
        int left = 2 * node, right = 2 * node + 1;
        return merge(query(l, r, left), query(l, r, right));
    }
    void flip(int l, int r, int node = 1){
        if(node >= N){
            return;
        }
        if((R[node] < l) || (r < L[node])){
            return;
        }
        if((l <= L[node]) && (R[node] <= r)){
            flip(node);
            return;
        }
        int left = 2 * node, right = 2 * node + 1;
        propogate(node);
        flip(l, r, left);
        flip(l, r, right);
        update(node);
    }
};
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    SegmentTree tree(n + 10);
    for(int i = 1; i <= n; ++i){
        if(s[i] == '1'){
            tree.flip(i, i);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int type;
        int l, r;
        cin >> type >> l >> r;
        if(type == 1){
            tree.flip(l, r);
        }
        else{
            cout << tree.query(l, r).curSquareSum << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
