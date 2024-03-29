//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int curr, int par, vector<int> adj[], vector<int> &vis) {
      
      for(int child : adj[curr]) {
          
          if(vis[child] == 0) {
              vis[child] = 1;
              bool res = dfs(child, curr, adj, vis);
              
              if(res == true)
                return true;
          }
          else if(child != par)
            return true;
      }
      
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++) {
            
            if(vis[i] == 0) {
                
                vis[i] = 1;
                bool res = dfs(i, -1, adj, vis);
                
                if(res == true) {
                    
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends