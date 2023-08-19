int get_centroid(int node, vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> subtree_size(n);
    function<int(int, int)> get_subtree_size;
    get_subtree_size = [&](int node, int par){
        int &res = subtree_size[node];
        res = 1;
        for(int i : adj[node]){
            if(i == par){
                continue;
            }
            res += get_subtree_size(i, node);
        }
        return res;
    };
 
    get_subtree_size(node, -1);
 
    bool repeat = true;
    while(repeat){
        repeat = false;
        for(int i : adj[node]){
            if(subtree_size[i] * 2 > n){
                subtree_size[node] -= subtree_size[i];
                subtree_size[i] += subtree_size[node];
 
                node = i;
                repeat = true;
 
                break;
            }
        }
    }
    return node;
}
