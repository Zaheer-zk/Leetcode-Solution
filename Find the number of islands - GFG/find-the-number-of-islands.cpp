//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
  int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
  // dfs for counting the connected island as connected node
  void dfs(int i, int j, int n, int m, vector<vector<char>>& grid) {
      
      //base case
      if(i < 0 or j < 0 or i == n or j == m) {
          return;
      }
      
      if(grid[i][j] == '0')
      return;
      
      //make grid as visited
      grid[i][j] = '0';
      
      //recursive call for all 8 direction
      for(int k = 0; k < 8; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          dfs(ni, nj, n, m, grid);
      }
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // island == 1
                if(grid[i][j] == '1') {
                    count++;
                    dfs(i,j,n,m,grid);  
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends