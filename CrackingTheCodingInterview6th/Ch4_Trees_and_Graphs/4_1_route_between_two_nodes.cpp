/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) {
 *         label = x;
 *         neighbors = new ArrayList<DirectedGraphNode>();
 *     }
 * };
 */
public class Solution {  
   /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    public boolean hasRoute(ArrayList<DirectedGraphNode> graph, 
                            DirectedGraphNode s, DirectedGraphNode t) {
        if (graph == null || graph.size() == 0) {
            return true;
        }

        Set<DirectedGraphNode> visited = new HashSet<>();

        return dfs(s, t, visited);
    }

    boolean dfs(DirectedGraphNode s, DirectedGraphNode t, Set<DirectedGraphNode> visited) {
        if (s == t) {
            return true;
        }

        visited.add(s);

        for (DirectedGraphNode n : s.neighbors) {
            if (!visited.contains(n)) {
                if (dfs(n, t, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
}