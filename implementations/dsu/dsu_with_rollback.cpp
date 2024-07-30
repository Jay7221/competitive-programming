class DSU {
public:
    vector<int> parent;
    vector<int> size;
    stack<pair<int, int>> history; // To store union operations for rollback

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            return find(parent[x]);
        }
        return parent[x];
    }

    int getSize(int x){
        x = find(x);
        return size[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false; // Already in the same set
        }

        // Union by size: attach smaller tree under larger tree
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];

        history.push({rootY, rootX}); // Push the union operation for potential rollback
        return true;
    }

    void rollback() {
        if (!history.empty()) {
            auto lastOperation = history.top();
            history.pop();

            int rootY = lastOperation.first;
            int rootX = lastOperation.second;

            parent[rootY] = rootY;
            size[rootX] -= size[rootY];
        }
    }
};
