import java.util.*;
class Solution {
	ArrayList<ArrayList<Integer>> tree; 
	int seats, N;
	long ans = 0;
	long dfs(int node, int parent){
		long cur = 0;
		for(int i = 0; i < tree.get(node).size(); ++i){
			int child = tree.get(node).get(i);
			if(child != parent){
				long tmp = dfs(child, node);
				ans += tmp / seats;
				if(tmp % seats != 0){
					++ans;
				}
				cur += tmp;
			}
		}
		cur += 1;
		return cur;
	}
	public long minimumFuelCost(int[][] roads, int seats) {
		N = 0;
		this.seats = seats;
	    
		for(int[] edge : roads){
	    		int u = edge[0], v = edge[1];
	    		N = Math.max(u, N);
	    		N = Math.max(v, N);
	       	}
	    
		N = N + 1;
		tree = new ArrayList<ArrayList<Integer>>(N);
		for(int i = 0; i < N; ++i){
	    		tree.add(new ArrayList<Integer>());
	      	}
		for(int[] edge : roads){
	    		int u = edge[0], v = edge[1];
	    		tree.get(u).add(v);
	    		tree.get(v).add(u);
	       	}
		dfs(0, -1);
		return ans;
	}
}
public class Feb12_2023{
	public static void main(String args[]){
		Solution s = new Solution();
		int[][] roads = new int[][]{{0, 1}, {0, 2}, {0, 3}};
		int seats = 5;
		System.out.println(s.minimumFuelCost(roads, seats));
	}
}
