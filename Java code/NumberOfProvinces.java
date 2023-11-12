import java.util.ArrayList;

public class NumberOfProvinces {
    private static void dfs(int node , ArrayList<ArrayList<Integer>>adjLs , int vis[]){
        vis[node] = 1;
        for(Integer it : adjLs.get(node)){
            if(vis[it]==0){
                dfs(it , adjLs , vis);
            }
        }
    }

    static int numProvinces(ArrayList<ArrayList<Integer>>adj, int V){
        ArrayList<ArrayList<Integer>>adjLS = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj.get(i).get(j)==1 && i!=j){
                    adjLS.get(i).add(j);
                    adjLS.get(j).add(i);
                }
            }
        }
        int vis[] = new int[V];
        int cnt = 0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i , adjLS , vis);
            }
        }
        return cnt;
    }
}
