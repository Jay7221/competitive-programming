import java.util.*;
class DSU{
	int par[];
	int rank[];
	DSU(int n){
		par = new int[n];
		rank = new int[n];
		for(int i = 0; i < n; ++i){
			rank[i] = 1;
			par[i] = i;
		}
	}
	int get(int u){
		if(u == par[u]){
			return u;
		}
		return par[u] = get(par[u]);
	}
	void merge(int u, int v){
		u = get(u);
		v = get(v);
		if(u != v){
			if(rank[u] < rank[v]){
				int tmp = u;
				u = v;
				v = tmp;
			}
			rank[u] += rank[v];
			par[v] = u;
		}
	}
	boolean same(int u, int v){
		return (get(u) == get(v));
	}
}
class Solution{
	static ArrayList<String> avoidExlosion(int mix[][], int n, int danger[][], int m) {
		ArrayList<String> ans = new ArrayList<String>();
		ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
		boolean vis[] = new boolean[n];
        for(int i = 0; i < n; ++i){
            graph.add(new ArrayList<Integer>());
        }
		DSU dsu = new DSU(n);
        for(int[] edge : danger){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
        }
		for(int i = 0; i < n; ++i){
			boolean flag = true;
			int u = mix[i][0] - 1;
			int v = mix[i][1] - 1;
			u = dsu.get(u);
			v = dsu.get(v);
			if(u != v){
				for(int[] e : danger){
					int x = e[0] - 1;
					int y = e[1] - 1;
					x = dsu.get(x);
					y = dsu.get(y);
					if(((u == x) && (v == y)) || ((u == y) && (v == x))){
						flag = false;
						break;
					}
				}
			}else{
				flag = true;
			}
			if(flag){
				dsu.merge(u, v);
				ans.add("YES");
			}else{
				ans.add("NO");
			}
		}
		return ans;
    }
	public static void main(String args[]){
		int n = 5;
		int m = 2;
		int mix[][] = new int[][]{{1, 2}, {2, 3}, {4, 5}, {3, 5}, {2, 4}};
		int danger[][] = new int[][]{{1, 3}, {4, 2}};
		ArrayList<String> s = avoidExlosion(mix, n, danger, m);
		System.out.println(s);
	}
}
