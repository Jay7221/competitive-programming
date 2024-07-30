import java.util.*;

class DSU {
    private int[] par, rank;

    public DSU(int n) {
        par = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    public int get(int i) {
        return par[i] == i ? i : (par[i] = get(par[i]));
    }

    public void merge(int u, int v) {
        u = get(u);
        v = get(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                int temp = u;
                u = v;
                v = temp;
            }
            par[v] = u;
            rank[u] += rank[v];
        }
    }

    public int getSize(int u) {
        return rank[get(u)];
    }
}

public class B {
    public static List<Integer> getTheGroups(int n, List<String> queryType, List<Integer> student1, List<Integer> student2) {
        List<Integer> res = new ArrayList<>();
        DSU dsu = new DSU(n + 2);
        for (int i = 0; i < queryType.size(); ++i) {
            int u = student1.get(i), v = student2.get(i);
            if (queryType.get(i).equals("Friend")) {
                dsu.merge(u, v);
            } else {
                res.add(dsu.get(u) != dsu.get(v) ? dsu.getSize(u) + dsu.getSize(v) : dsu.getSize(u));
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int n = 3;
        List<String> queryType = Arrays.asList("Friend", "Total");
        List<Integer> student1 = Arrays.asList(1, 2);
        List<Integer> student2 = Arrays.asList(2, 3);

        List<Integer> result = getTheGroups(n, queryType, student1, student2);
        System.out.println(result); // Output the result
    }
}
