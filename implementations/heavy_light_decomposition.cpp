struct HLD{
    vector<int> parent, depth, head, heavy, pos;
    vector<int> arr;
    SegmentTree s;
    int cur_pos;
    int dfs(int v, vector<vector<int>> &graph){
        int size = 1;
        int max_c_size = 0;
        for(int c : graph[v]){
            if(c != parent[v]){
                parent[c] = v;
                depth[c] = depth[v] + 1;
                int c_size = dfs(c, graph);
                size += c_size;
                if(c_size > max_c_size){
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }
    void decompose(int v, int h, vector<vector<int>> &graph){
        head[v] = h;
        pos[v] = cur_pos;
        ++cur_pos;

        if(heavy[v] != -1){
            decompose(heavy[v], h, graph);
        }
        for(int c : graph[v]){
            if((c != parent[v]) && (c != heavy[v])){
                decompose(c, c, graph);
            }
        }

    }
    HLD(vector<vector<int>> &graph){
        int n = graph.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        arr = vector<int>(n);

        cur_pos = 0;

        dfs(0, graph);
        decompose(0, 0, graph);
        s = SegmentTree(n);
    }

    void set(int v, int val){
        arr[pos[v]] = val;
        s.set(pos[v], val);
    }

    int get(int l, int r){
        return s.get(l, r);
    }

    int query(int a, int b){
        int res = 0;
        while(head[a] != head[b]){
            if(depth[head[a]] > depth[head[b]]){
                swap(a, b);
            }
            int cur_heavy_path_max = get(pos[head[b]], pos[b]);
            res = max(res, cur_heavy_path_max);

            b = parent[head[b]];
        }
        if(depth[a] > depth[b]){
            swap(a, b);
        }
        int last_heavy_path_max = get(pos[a], pos[b]);
        res = max(res, last_heavy_path_max);

        return res;
    }

};
