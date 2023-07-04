#include <bits/stdc++.h>

#define el '\n'

typedef long long ll;
typedef long double ld;

#define Beevo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5 + 5, ALPHA = 26, LOG = 20;

ll oldVal[N];
int id, timer, sz[N], trie[N][ALPHA], leaf[N], up[N][LOG], in[N], out[N];

struct Query {
    int t, i, k, x;
    string s;
};

struct Node {
   ll sum = 0;
};

struct SegTree {
   ll lazy[N * 4];
   Node tree[N * 4];
   Node neutral = Node();

   Node merge(Node u, Node v) {
       return {u.sum + v.sum};
   }

   void propagate(int x, int lX, int rX) {
       tree[x].sum += lazy[x] * (rX - lX + 1);

       if (lX != rX) {
           lazy[x * 2] += lazy[x];
           lazy[x * 2 + 1] += lazy[x];
       }

       lazy[x] = 0;
   }

   void update(int x, int lX, int rX, int l, int r, int val) {
       propagate(x, lX, rX);

       if (lX > r || rX < l)
           return;

       if (lX >= l && rX <= r) {
           tree[x].sum += 1LL * (rX - lX + 1) * val;

           if (lX != rX) {
               lazy[x * 2] += val;
               lazy[x * 2 + 1] += val;
           }

           return;
       }

       int m = (lX + rX) >> 1;

       update(x * 2, lX, m, l, r, val);
       update(x * 2 + 1, m + 1, rX, l, r, val);

       tree[x] = merge(tree[x * 2], tree[x * 2 + 1]);
   }

   Node query(int x, int lX, int rX, int l, int r) {
       if (lX > r || rX < l)
           return neutral;

       propagate(x, lX, rX);

       if (lX >= l && rX <= r)
           return tree[x];

       int m = (lX + rX) >> 1;

       Node u = query(x * 2, lX, m, l, r);
       Node v = query(x * 2 + 1, m + 1, rX, l, r);

       return merge(u, v);
   }
} st;

int insert(int cur, string &s) {
    int ch;

    for (auto &i: s) {
        ch = i - 'a';

        if (!trie[cur][ch])
            trie[cur][ch] = ++id;

        up[trie[cur][ch]][0] = cur, cur = trie[cur][ch];

        for (int k = 1; k < LOG; k++)
            up[cur][k] = up[up[cur][k - 1]][k - 1];
    }

    return cur;
}

int kth(int cur, int k) {
    for (int i = LOG - 1; i >= 0; i--) {
        if (k & (1 << i))
            cur = up[cur][i];
    }

    return cur;
}

void dfs(int u) {
    in[u] = timer++;

    for (int i = 0; i < ALPHA; i++) {
        if (trie[u][i])
            dfs(trie[u][i]);
    }

    out[u] = timer - 1;
}

void testCase() {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;

        sz[i] = s.size();
        leaf[i] = insert(0, s);
    }

    int q;
    cin >> q;

    vector<Query> v;
    int t, i, k, x, u, cnt = 0;
    for (int j = 0; j < q; j++) {
        s.clear();

        cin >> t >> i;

        i--;

        if (t == 1) {
            cin >> k >> x;

            k--;
        }
        else if (t == 2) {
            cin >> k >> s;

            k--;

            sz[n + cnt] = k + 1 + s.size();
            leaf[n + cnt] = insert(kth(leaf[i], sz[i] - k - 1), s);

            cnt++;
        }

        v.push_back({t, i, k, x, s});
    }

    dfs(0);

    cnt = 0;
    for (auto &j: v) {
        t = j.t, i = j.i, k = j.k, x = j.x, s = j.s;

        if (t == 1) {
            u = kth(leaf[i], sz[i] - k - 1);

            st.update(1, 0, N - 1, in[u], out[u], x);
        }
        else if (t == 2) {
            oldVal[n + cnt] = st.query(1, 0, N - 1, in[leaf[n + cnt]], in[leaf[n + cnt]]).sum;

            cnt++;
        }
        else
            cout << st.query(1, 0, N - 1, in[leaf[i]], in[leaf[i]]).sum - oldVal[i] << el;
    }
}

signed main() {
    Beevo

    int t = 1;
//    cin >> t;

    while (t--)
        testCase();
}
