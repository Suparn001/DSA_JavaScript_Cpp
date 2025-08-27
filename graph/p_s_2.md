
# Bipartite Graph

**Difficulty:** Medium  
**Accuracy:** 31.25%  
**Submissions:** 202K+  
**Points:** 4  
**Average Time:** 15m  

---

## Problem Statement

Given a Graph with **V vertices** (Numbered from 0 to V-1) and **E edges**.  
Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color.  
This means we can divide the graph’s vertices into two distinct sets where:

- All edges connect vertices from one set to vertices in the other set.  
- No edges exist between vertices within the same set.  

---

## Examples

### Example 1
**Input:**  
```
V = 3, edges[][] = [[0, 1], [1, 2]]
```  
**Output:**  
```
true
```  
**Explanation:** The given graph can be colored in two colors, so it is a bipartite graph.

---

### Example 2
**Input:**  
```
V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]
```  
**Output:**  
```
false
```  
**Explanation:** The given graph cannot be colored in two colors such that the color of adjacent vertices differs.  

---

## Constraints

- 1 ≤ V ≤ 2 * 10^5  
- 1 ≤ edges.size() ≤ 10^5  
- 1 ≤ edges[i][j] ≤ 10^5  

---

## Expected Complexities

- **Time Complexity:** O(V + E)  
- **Space Complexity:** O(V + E)  

---

## DFS Solution

```cpp
class Solution {
public:

bool isGraphBipartite(int node,vector<vector<int>> &adj, vector<int> &color){
    
    
    for(int j=0;j<adj[node].size();j++){
        if(color[adj[node][j]]==-1){
            color[adj[node][j]] = (color[node]+1)%2;
            
            if(!isGraphBipartite(adj[node][j],adj,color)){
                return 0;
            } 
        }
        else{
            if(color[node] == color[adj[node][j]]){
                return 0;
                
            }
        }
    }
    return 1;
}


    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V, -1);
        vector<vector<int>> adj(V);

        for (auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                color[i]=0;
              if(!isGraphBipartite(i,adj,color)){
                  return 0;
              }
            }
        }
        return 1;
    }
};
```

---

## BFS Solution

```cpp
class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V, -1);
        vector<vector<int>> adj(V);

        for (auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int i = 0; i < adj[node].size(); i++) {
                        if (color[adj[node][i]] == -1) {
                            color[adj[node][i]] = (color[node] + 1) % 2;
                            q.push(adj[node][i]);
                        } else {
                            if (color[node] == color[adj[node][i]]) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }

        return 1;
    }
};
```

---

## Notes

- Both DFS and BFS solutions achieve the same goal.  
- DFS uses recursion to check bipartite property.  
- BFS uses a queue for level-order traversal to check bipartite property.  

---

