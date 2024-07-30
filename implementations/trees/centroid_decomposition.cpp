struct CentroidDecomposition{
    vector<set<int>> tree;
    vector<int> par;
    vector<int> sub;

    CentroidDecomposition(vector<set<int>> &tree) : tree(tree) {
        int n = tree.size();
        par.resize(n);
        sub.resize(n);
        build(0, -1);
    }

    void build(int u, int p){
        int n = get_subtree_size(u, p);             // find the size of each subtree
        int centroid = get_centroid(u, p, n);          // find the centroid
        par[centroid] = p;

        // for each tree resulting from the removal of the centroid
        set<int> children = tree[centroid];
        for(int v : children){
            tree[v].erase(centroid);        // remove the edge to disconnect the component from the tree
            tree[centroid].erase(v);
            build(v, centroid);
        }
    }

    int get_subtree_size(int u, int p){
        sub[u] = 1;
        for(int v : tree[u]){
            if(v != p){
                sub[u] += get_subtree_size(v, u);
            }
        }
        return sub[u];
    }

    int get_centroid(int u, int p, int n){
        for(int v : tree[u]){
            if((v != p) && ((2 * sub[v]) > n)){
                return get_centroid(v, u, n);
            }
        }
        return u;
    }

    int operator[](int i){
        return par[i];
    }
};
