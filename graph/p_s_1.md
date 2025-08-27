# Directed Graph Cycle Detection

## Problem Statement
Given a **Directed Graph** with `V` vertices (numbered `0` to `V-1`) and `E` edges, check whether it contains any **cycle** or not.

The graph is represented as a **2D vector** `edges[][]`, where each entry `edges[i] = [u, v]` denotes an edge from vertex `u` to vertex `v`.

---

## Examples

**Example 1:**
```
Input:  
V = 4  
edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]  

Output:  
true  

Explanation:  
The diagram clearly shows a cycle → 0 → 2 → 0
```

**Example 2:**
```
Input:  
V = 4  
edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]  

Output:  
false  

Explanation:  
No cycle in the graph
```

---

## Constraints
- 1 ≤ V, E ≤ 10^5  
- u ≠ v  

---

## Approach

We solve this problem using **DFS with recursion stack tracking**:  
1. Maintain two arrays:  
   - `visited[]`: Keeps track of whether a node is already visited.  
   - `path[]`: Keeps track of the recursion stack (active path).  

2. For each unvisited node:  
   - Start DFS and mark it in `path[]`.  
   - If any adjacent node is already in the current path, then we found a **cycle**.  
   - After DFS call ends, backtrack by unmarking from `path[]`.  

3. If no cycle is found after traversing all vertices, return `false`.  

**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)  

---

## Solution (C++ DFS)
```cpp
class Solution {
  public:
  
  bool DetectDirectCycle(int node, vector<vector<int>> &adj, vector<bool>& path, vector<bool>& visited) {
      path[node] = 1;
      visited[node] = 1;
      
      for (int j = 0; j < adj[node].size(); j++) {
          int next = adj[node][j];
          
          if (path[next]) {
              return true;  // cycle detected
          }
          
          if (!visited[next] && DetectDirectCycle(next, adj, path, visited)) {
              return true;
          }
      }
      
      path[node] = 0;  // backtrack
      return false;
  }
  
  bool isCyclic(int V, vector<vector<int>> &edges) {
      vector<vector<int>> adj(V);
      vector<bool> path(V, 0);
      vector<bool> visited(V, 0);
      
      // Build adjacency list
      for (auto &i : edges) {
          adj[i[0]].push_back(i[1]);
      }
      
      // Check each component
      for (int i = 0; i < V; i++) {
          if (!visited[i] && DetectDirectCycle(i, adj, path, visited)) {
              return true;
          }
      }
      
      return false;
  }
};
```
## Solution (C++ DFS)
```cpp


```


