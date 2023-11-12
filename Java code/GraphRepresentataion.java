/**
 * GraphRepresentataion
 */
import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class GraphRepresentataion {
    public static void main(String[] args){
        int n = 3 , m=3;
        int adj[][] = new int[n+1][n+1]; // adjacency matrix 

        // if weight wt is given adj[u][v]= wt
        // edge 1--2
        adj[1][2]=1;
        adj[2][1]=1;
        // edge 2--3
        adj[2][3]=1;
        adj[3][2]=1;
        // edge 1--3
        adj[1][3]=1;
        adj[3][1]=1;


        // Adjacency Matrix 
        ArrayList<ArrayList<Integer>> adj_list = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<=n;i++){
            adj_list.add(new ArrayList<Integer>());

        }
        // edge 1--2
        adj_list.get(1).add(2); 
        adj_list.get(2).add(1);

        //edge 2--3
        adj_list.get(2).add(3);
        adj_list.get(3).add(2);
        // edge 1--3
        adj_list.get(1).add(3);
        adj_list.get(3).add(1);

        System.out.println("Printing Graph");
        for(int i=1;i<n;i++){
            for(int j=0;j<adj_list.get(i).size();j++)
            System.out.print(adj_list.get(i).get(j)+" ");
            System.out.println();
        }
    }
    
}